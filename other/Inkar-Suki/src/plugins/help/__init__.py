import json, os, sys, nonebot
from pathlib import Path
from nonebot.adapters.onebot.v11 import MessageSegment
from nonebot import on_command
from tabulate import tabulate
from .picture import main as pic
TOOLS = nonebot.get_driver().config.tools_path
sys.path.append(str(TOOLS))
from file import read
from config import Config

help = on_command("help", aliases={"帮助"}, priority=5)
css = """
<style>
            ::-webkit-scrollbar 
            {
            display: none;
                
            }
            table { 
            border-collapse: collapse; 
                } 
              table, th, td { 
                border: 1px solid rgba(0,0,0,0.05); 
                font-size: 0.8125rem; 
                font-weight: 500; 
              } 
              th, td { 
              padding: 15px; 
              text-align: left; 
              }
              @font-face
              {
                  font-family: Custom;
                  src: url("略略略");
              }
            </style>"""
css = css.replace("略略略",Config.font_path)
path = Config.global_path
final_plugin_information_file_path = {}
name = {}
version = {}
author = {}
json_ = {}
desc = {}
admin = {}
aliases = {}
table = []
html_path = Config.html_path
imgPath = Config.help_image_save_to

@help.handle()
async def help_():
    os.system(f"rm -rf {html_path}")
    all_cmd = os.listdir(path)
    for plugin in all_cmd:
        final_plugin_information_file_path[plugin] = path + plugin + "/info.json"
        cache = read(final_plugin_information_file_path[plugin])
        json_[plugin] = cache
        json_[plugin] = json.loads(json_[plugin])
        cache = json_[plugin]
        name[plugin] = cache["name"]
        version[plugin] = cache["version"]
        author[plugin] = cache["author"]
        desc[plugin] = cache["desc"]
        admin[plugin] = cache["admin"]
        aliases[plugin] = cache["aliases"]
    table.append(["插件名称","插件版本","插件介绍","插件作者","权限等级","别名"])
    for i in all_cmd:
        table.append([name[i],version[i],desc[i],author[i],admin[i],aliases[i]])
    if os.path.exists(html_path) == False:
        msg = str(tabulate(table,headers="firstrow",tablefmt="html"))
        table.clear()
        html = "<div style=\"font-family:Custom\">" + msg.replace("$", "<br>") + "</div>"+css
        file0 = open(html_path,mode="w")
        file0.write(html)
        file0.close()
    if os.path.exists(imgPath) == False:
        pic_status = pic()
        if pic_status == "200 OK":
            help_path = Path(Config.help_image_save_to).as_uri()
            pic_msg = MessageSegment.image(help_path)
            msg = "喵……以下为帮助信息：" + pic_msg
        else:
            msg = f"唔……帮助图片生成失败了哦，请联系管理员尝试清除缓存。\n错误信息如下：{pic_status}"
    else:
        help_path = Path(Config.help_image_save_to).as_uri()
        pic_msg = MessageSegment.image(help_path)
        msg = "喵……以下为帮助信息：" + pic_msg
    await help.finish(msg)