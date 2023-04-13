var userlist = 
["AC？别闹！","_XHZS_XY_","zzzzzz2","EZ_XHX","Lavaloon","Strelitzia_"];
var pages = 1;
var cd = 10000;
function onSearch(obj)
{
    var storeId=document.getElementById('store');
    var rowsLength=storeId.rows.length;
    var key=document.getElementById('key').value;
    for(var i=1;i < rowsLength;i++)
    {
        var searchText=storeId.rows[i].cells[0].innerHTML;
        if(key=="*"||searchText.match(key))
            storeId.rows[i].style.display='';
        else
            storeId.rows[i].style.display='none';
    }
};
str='<div><select onchange="onSearch()" name="key" id="key"><option value="*">*</option>';
for(var i=0;i < userlist.length;i++)
    str+='<option value="'+userlist[i]+'">'+userlist[i]+'</option>';
str+='</select></div><table id="store" style="white-space: nowrap;"><tr><th>用户</th><th>题号</th><th>标题</th></tr></table>';
document.body.innerHTML = "<h1 style='text-align:center;color:red;font-family:Microsoft Yahei'>内卷监视工具</h1>";
document.body.innerHTML += "<b style='text-align:center;font-family:FangSong'>运筹首页之中，偷袭千里之外&#128517;</b><hr>" + str;
//<!-- Output Emoji & Option -->
var colors=['rgb(191, 191, 191)','rgb(254, 76, 97)','rgb(243, 156, 17)','rgb(255, 193, 22)','rgb(82, 196, 26)','rgb(52, 152, 219)','rgb(157, 61, 207)','rgb(14, 29, 105)'];
var name="灰红橙黄绿蓝紫黑";
var lst=Array();
var cnt=0;
function PARSE(First=false)
{
    cnt=(cnt+1)%userlist.length;
    var user=userlist[cnt];
    var Pagenum=1;if(First)Pagenum=pages;
    for(;Pagenum>0;Pagenum--)
    {
        var httpRequest=new XMLHttpRequest();
        httpRequest.open('GET','https://www.luogu.com.cn/record/list?user='+user+'&page='+Pagenum,false);
        httpRequest.send();
        if(httpRequest.readyState==4&&httpRequest.status==200)
        {
            var content=httpRequest.responseText;
            var patten=/decodeURIComponent\(".*?"\)/;
            content=patten.exec(content)[0];
            content=content.substr(20,content.length-22);
            content=JSON.parse(decodeURIComponent(content));
            var prob,col,pid,title;
            for(var i=Math.min(content.currentData.records.result.length-1,19);i>=0;i--)
                if(content.currentData.records.result[i].status==12&&content.currentData.records.result[i].id>lst[cnt])
                {
                    prob=content.currentData.records.result[i].problem;
                    col=colors[prob.difficulty];
                    pid=prob.pid;
                    title=prob.title;
                    document.getElementById('store').childNodes[0].innerHTML
                        +='<tr><td>'+user+'</td><td>'+pid+'</td><td>'+
                            "<a style='color:"+col+"' href='https://www.luogu.com.cn/problem/"+pid+"' target='_blank'>"
                        +title+"</a>"+'</td></tr>';
                    if(!First)
                        alert(user+" 刚刚卷了"+name[prob.difficulty]+"题 "+pid+" "+title);
                    lst[cnt]=content.currentData.records.result[i].id
                }
        }
    }
}
for(var i=0;i < userlist.length;i++)lst[i]=0;
for(var i=0;i < userlist.length;i++)PARSE(true);
window.setInterval(PARSE,cd);