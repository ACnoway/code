import time
import random
import datetime as dt


def biaoti():
    print("     ? Actxt平台：盖亚?")
    print("  在Actxt，享受变身的快乐")
    print("_____________________________________")


banben = "0.41"  # 在更新日志里会被调用，但版本好像不是这个


class Clock:  # 打卡

    def yunshi(self):  # 运势
        global yss
        global ys
        yss = random.randint(1, 6)
        if yss == 1:
            ys = "大凶"
        if yss == 2:
            ys = "凶"
        if yss == 3:
            ys = "中平"
        if yss == 4:
            ys = "小吉"
        if yss == 5:
            ys = "中吉"
        if yss == 6:
            ys = "大吉"
        return ys

    def jili(self):  #吉利的运势
        global ys1
        global ysy1b
        global ysy1n
        ys1 = random.randint(1, 30)
        if ys1 == 1:
            ysy1b = "写作文              "
            ysy1n = "非常有文采          "
        if ys1 == 2:
            ysy1b = "搞基                "
            ysy1n = "友谊地久天长        "
        if ys1 == 3:
            ysy1b = "扶老奶奶过马路      "
            ysy1n = "RP++                "
        if ys1 == 4:
            ysy1b = "开电脑              "
            ysy1n = "电脑的状态也很好    "
        if ys1 == 5:
            ysy1b = "刷题                "
            ysy1n = "成为虐题狂魔        "
        if ys1 == 6:
            ysy1b = "重构代码            "
            ysy1n = "代码质量明显提高    "
        if ys1 == 7:
            ysy1b = "写作业              "
            ysy1n = "都会写，写的全对    "
        if ys1 == 8:
            ysy1b = "参加模拟赛          "
            ysy1n = "可以AK虐全场        "
        if ys1 == 9:
            ysy1b = "睡觉                "
            ysy1n = "养足精力，明日再战  "
        if ys1 == 10:
            ysy1b = "打chunithm          "
            ysy1n = "你虹了              "
        if ys1 == 11:
            ysy1b = "祭祀                "
            ysy1n = "获得祖宗的庇护      "
        if ys1 == 12:
            ysy1b = "膜拜大神            "
            ysy1n = "接受神犇光环照耀    "
        if ys1 == 13:
            ysy1b = "洗澡                "
            ysy1n = "你多久没洗澡了？    "
        if ys1 == 14:
            ysy1b = "继续完成WA的题      "
            ysy1n = "下一次就可以AC了    "
        if ys1 == 15:
            ysy1b = "熬夜                "
            ysy1n = "事情终究是可以完成的"
        if ys1 == 16:
            ysy1b = "泡妹子              "
            ysy1n = "说不定可以牵手      "
        if ys1 == 17:
            ysy1b = "考试                "
            ysy1n = "考的全会，蒙的全对  "
        if ys1 == 18:
            ysy1b = "背诵课文            "
            ysy1n = "看一遍就背下来了    "
        if ys1 == 19:
            ysy1b = "体育锻炼            "
            ysy1n = "身体棒棒哒          "
        if ys1 == 20:
            ysy1b = "吃饭                "
            ysy1n = "人是铁饭是钢        "
        if ys1 == 21:
            ysy1b = "上课                "
            ysy1n = "100%消化            "
        if ys1 == 22:
            ysy1b = "装弱                "
            ysy1n = "谦虚最好了          "
        if ys1 == 23:
            ysy1b = "学习珂学            "
            ysy1n = "珂朵莉太可爱了      "
        if ys1 == 24:
            ysy1b = "纳财                "
            ysy1n = "要到好多Money       "
        if ys1 == 25:
            ysy1b = "上B站               "
            ysy1n = "愉悦身心            "
        if ys1 == 26:
            ysy1b = "发朋友圈            "
            ysy1n = "分享是种美德        "
        if ys1 == 27:
            ysy1b = "装逼                "
            ysy1n = "获得众人敬仰        "
        if ys1 == 28:
            ysy1b = "玩网游              "
            ysy1n = "犹如神助            "
        if ys1 == 29:
            ysy1b = "打sdvx              "
            ysy1n = "您暴了              "
        if ys1 == 30:
            ysy1b = "出行                "
            ysy1n = "一路顺风            "

    def xiong(self):  #凶的运势 啊呜~
        global ys11
        global ysy11b
        global ysy11n
        ys11 = random.randint(1, 30)
        if ys11 == 1:
            ysy11b = "写作文"
            ysy11n = "可能会离题"
        if ys11 == 2:
            ysy11b = "搞基"
            ysy11n = "会被掰弯"
        if ys11 == 3:
            ysy11b = "扶老奶奶过马路"
            ysy11n = "会被讹"
        if ys11 == 4:
            ysy11b = "开电脑"
            ysy11n = "意外的死机故障不可避免"
        if ys11 == 5:
            ysy11b = "刷题"
            ysy11n = "容易WA"
        if ys11 == 6:
            ysy11b = "重构代码"
            ysy11n = "越改越乱"
        if ys11 == 7:
            ysy11b = "写作业"
            ysy11n = "上课讲了这些了吗"
        if ys11 == 8:
            ysy11b = "参加模拟赛"
            ysy11n = "注意爆零"
        if ys11 == 9:
            ysy11b = "睡觉"
            ysy11n = "翻来覆去睡不着"
        if ys11 == 10:
            ysy11b = "打chunithm"
            ysy11n = "今天状态不好"
        if ys11 == 11:
            ysy11b = "祭祀"
            ysy11n = "祖宗不知干啥就不鸟你"
        if ys11 == 12:
            ysy11b = "膜拜大神"
            ysy11n = "被大神鄙视"
        if ys11 == 13:
            ysy11b = "洗澡"
            ysy11n = "当心着凉"
        if ys11 == 14:
            ysy11b = "继续完成WA的题"
            ysy11n = "然而变成了TLE"
        if ys11 == 15:
            ysy11b = "熬夜"
            ysy11n = "爆肝"
        if ys11 == 16:
            ysy11b = "泡妹子"
            ysy11n = "一定会被拒绝"
        if ys11 == 17:
            ysy11b = "考试"
            ysy11n = "作弊会被抓"
        if ys11 == 18:
            ysy11b = "背诵课文"
            ysy11n = "记忆力只有50Byte"
        if ys11 == 19:
            ysy11b = "体育锻炼"
            ysy11n = "消耗的能量全吃回来了"
        if ys11 == 20:
            ysy11b = "吃饭"
            ysy11n = "小心变胖啊"
        if ys11 == 21:
            ysy11b = "上课"
            ysy11n = "反正你听不懂"
        if ys11 == 22:
            ysy11b = "装弱"
            ysy11n = "被看穿"
        if ys11 == 23:
            ysy11b = "学习珂学"
            ysy11n = "珂朵莉不知干啥不理你"
        if ys11 == 24:
            ysy11b = "纳财"
            ysy11n = "然而今天并没有财运"
        if ys11 == 25:
            ysy11b = "上B站"
            ysy11n = "会被教练发现"
        if ys11 == 26:
            ysy11b = "发朋友圈"
            ysy11n = "会被当做卖面膜的"
        if ys11 == 27:
            ysy11b = "装逼"
            ysy11n = "被识破"
        if ys11 == 28:
            ysy11b = "玩网游"
            ysy11n = "匹配到一群猪队友"
        if ys11 == 29:
            ysy11b = "打sdvx"
            ysy11n = "今天状态不好"
        if ys11 == 30:
            ysy11b = "出行"
            ysy11n = "路途必然坎坷"

    def laohuangli(self):
        #好的我理一下，yss1~6，是运势大凶~大吉
        #ys1也不知道是干什么的（大雾
        #怎么一堆重复的代码
        #好的把它们移至别的函数
        clock.yunshi()
        print("               §", ys, "§")
        clock.jili()
        clock.xiong()
        print("宜:", ysy1b, " 忌:", ysy11b)
        print(ysy1n, "    ", ysy11n)
        print(" ")
        clock.jili()
        clock.xiong()
        print("宜:", ysy1b, " 忌:", ysy11b)
        print(ysy1n, "    ", ysy11n)
        print("")

    def laohuangli_zhubian(self):
        clock.jili()
        print("               §大吉§")
        print("宜:泡妹子           ", " 万事皆宜")
        print("一定可以牵手！      ")
        print(" ")
        print("宜:", ysy1b, "！！！恭迎主编！！！")
        print(ysy1n)
        print("")
        zb = 1


clock = Clock()


def gongnengliebiao():
    print(" ")
    print("功能列表：")
    print("1:小游戏")
    print("2:阶乘")
    print("3:更新日志")
    print("4:题库")
    print("5:跳题")
    print(" ")
    print(" ")
    gnxz2 = int(input("你的选择?"))
    print(" ")
    if gnxz2 == 1:
        print("欢迎进入小游戏")
        print("当前游戏:")
        print("1：猜数游戏")
        print(" ")
        print(" ")
        yxxz = int(input("你的选择？"))
        print(" ")
        if yxxz == 1:
            caishuyouxi()
    if gnxz2 == 2:
        jisuanjiecheng()
    if gnxz2 == 3:
        gengxinrizhi()
        fh3 = int(input("输入1返回功能列表"))
        if fh3 == 1:
            gongnengliebiao()
    if gnxz2 == 4:
        problems.tikujuqing()
        problems.tiku()
    if gnxz2 == 5:
        problems.tiaoti()


def caishuyouxi():
    print("欢迎进入猜数游戏：")
    print("游戏规则(1)")
    print("返回功能列表(2)")
    print(" ")
    print(" ")
    csxz = int(input("你的选择?"))
    print(" ")
    if csxz == 1:
        print("游戏规则:")
        print("您共有11次机会，每次猜测会消耗一次机会，当您猜中时系统会告诉您结果和剩余的机会数。(1-1000)")
        if csxz == 1:
            print("系统已选好数，游戏即将开始")
            print(" ")
            css = random.randint(1, 999)
            jh = 11
        while jh != 0:
            print("您猜的数？")
            print("输入0退出")
            cds = int(input(""))
            if cds == 0:
                break
            if cds > css:
                print("猜大了啊！")
                jh = jh - 1
                print("您还有", jh, "次机会")
            if cds < css:
                print("猜小啦！")
                jh = jh - 1
                print("您还有", jh, "次机会")
            if cds == css:
                jh = jh - 1
                print("恭喜您猜对了,这个数是", css, "您还有", jh, "次机会。")
                print(" ")
                print(" ")
                break
        if jh == 0:
            print("您已失败")
            print(" ")
            print("妨碍制作组的渣渣！这么简单都没猜对，我不操你ba(祖安作者)")
            print(" ")
            print("这个数是", css)
        fh1 = int(input("输入1返回功能列表"))
        if fh1 == 1:
            print(" ")
            print("妨碍制作组的渣渣！这么简单都半途而废，我不操你ba(祖安作者)")
            print(" ")
            print(" ")
            gongnengliebiao()
    if csxz == 2:
        print(" ")
        gongnengliebiao()


def jisuanjiecheng():
    num = int(input("请输入一个数字: "))
    factorial = 1
    if num < 0:
        print("抱歉，负数没有阶乘")
    elif num == 0:
        print("0 的阶乘为 1")
    else:
        for i in range(1, num + 1):
            factorial = factorial * i
        print("%d 的阶乘为 %d" % (num, factorial))
        print(" ")
        print(" ")
        fh2 = int(input("输入1返回功能列表"))
        if fh2 == 1:
            gongnengliebiao()


class Problems:  #第4~5项

    def tikujuqing(self):
        print("zzz成员 汽水味儿啊：终于更新题库了，等了多久？")
        #
        time.sleep(2)
        print("zzz成员 岚：不知道，好像等了27个版本。")
        #
        time.sleep(2)
        print("          \  作者  /")
        print("           >      <")
        print("          催更   催更")
        print("            (×﹏×) ")
        #
        time.sleep(3)
        print(" 不过，他来啦 b（￣▽￣）d")
        #
        time.sleep(2)
        print("zzz成员 寻:有什么题吗？")
        #
        time.sleep(2)
        print("= =* 作者眉头一皱，发现事情并不简单")
        #
        time.sleep(2)
        print("作者：有..有啊，有几道题")
        #
        time.sleep(2)
        print("zzz全体成员:拿来瞧瞧！")
        print(" ")
        print("回车继续...")
        xxsadsa = str(input())

    def tiku(self):
        print(" ")
        print("题目列表")
        print("")
        print("P1001:A+B问题(来源：洛谷)")
        print("P3353：在她窗外闪耀的星星(来源：洛谷；zzz制作组转载并更改部分)")
        print("")
        print("0:返回功能列表")
        tkxz = str(input("你的选择？"))
        print(" ")
        if tkxz == "P1001":
            problems.p1001()
        if tkxz == 'P3353':
            problems.p3353()
        if tkxz == '0':
            problems.gongnengliebiao()

    def p1001(self):
        print("")
        print("题目描述:")
        print(" ")
        print("输入两个整数 a,b，输出它们的和。")
        print("")
        print("输入格式:两个整数，中间以空格分开。")
        print("")
        print("输出格式:一个整数。")
        print("")
        print("输入输出样例")
        print("输入#1    输出#1")
        print("30 20     50")
        print("")
        print("")
        print("提交代码(1)")
        print("返回题目列表(2)")
        fh4 = int(input("你的选择？"))
        if fh4 == 1:
            print("")
            problems.yuyan('P1001')
            print(" ")
            print("返回题目（1）")
            print("返回题目列表（2）")
            p1001pcfh = int(input("你的选择？"))
            if p1001pcfh == 1:
                problems.p1001()
            if p1001pcfh == 2:
                problems.tiku()
        if fh4 == 2:
            problems.tiku()

    def p1001pingceji(self):
        print("#1             #2             #3             #4             #5")
        time.sleep(3)
        print("")
        print(
            "    AC               AC             AC            AC              AC"
        )
        print("")
        print(
            "2ms/504.00KB   2ms/504.00KB   2ms/504.00KB   2ms/504.00KB   2ms/504.00KB"
        )

    def p3353(self):
        print("P3353 在你窗外闪耀的星星")
        print(" ")
        print("题目背景")
        print(" ")
        print(
            "飞逝的的时光不会模糊我对你的记忆。难以相信从我第一次见到你以来已经过去了4年。我仍然还生动地记得，4年前，在美丽的实验中学，从我看到你微笑着走出教室，你将头向后仰，柔和的晚霞照耀着你玫瑰色的脸颊。我明白，我已经沉醉于你了。之后，经过几个月的观察和窥探，你的优雅与智慧，你对待生活的态度和你对未来的愿望深切地在我心中留下了印象。你是迷人的阳光女孩，我总是梦想着与你分享余生。唉，实际上你远远超过了我最疯狂的梦想。我不知道如何桥起我与你之间的鸿沟。所以我没有任何计划，仅仅只是等待，等待一个适当的机会到来。直到现在，毕业的到来，我意识到我是个傻瓜，我应该创造机会并且抓住它而不只是等待。"
        )
        print(" ")
        print(
            "这些日子里，我和我的朋友、室友、同学一个接一个地分开。我仍无法相信，在挥手之后，这些熟悉的面孔很快就会从我们的生活中消失，仅仅留下回忆。我明天就将离开学校。你已经计划远走高飞，追求你的未来，实现你的梦想。如果没有命运，也许我们不会再次相遇。所以今晚，我正在你的宿舍楼下徘徊，希望能偶然遇见你。但矛盾的是，你的美貌一定会使我心跳加速，我笨拙的舌头也许无法吐出一个字。我不记得我曾多少次经过你的宿舍楼，每次都希望看到你出现在阳台上或是窗台上。我不记得这个想法曾多少次在我的脑海中涌出：打电话叫她一起吃晚饭或是聊聊天。但每次，考虑到你的优秀和我的平凡，胆怯的优势超越勇气驱使我静静地离开。"
        )
        print(" ")
        print(
            "毕业，意味着中学生活的终结。这些光荣与浪漫的时代结束。你可爱的微笑是我原来努力学习的动力，这单相思的爱情会被密封，作为一个我心灵深处的记忆。毕业，也意味着新生活的开始，一个到达光明未来的足迹。我真希望你在国外天天开心，一切顺利。同时，我将努力从幼稚中走出来，变得更加成熟。我的理想将是在现实中追求我的爱与幸福，我永远不会放弃。"
        )
        print(" ")
        print("再见了，我的公主！")
        print(" ")
        print(
            "如果有一天，在某个天涯海角，我们有机会相聚，即使是白发苍苍的男人和女人，在那个时候，我希望我们可以成为好朋友来自豪地分享这个记忆，重温年轻快乐的激情。如果这个机会永远没有到来，我希望我是天空中的星星，在你的窗外闪烁。远远地保佑着你，就像一个朋友，每天晚上陪伴在你左右，一同分享甜美的梦亦或是一同经历可怕的梦。"
        )
        print("")
        print("题目描述")
        print(" ")
        print(
            "现在问题来了：天空可以理解为一条数轴，在这条数轴上分布着许多颗星星，对于每颗星星都有它的位置 X_i和自身的亮度 B_i。而窗户所能看到的范围是一个给出的参数W，我们看到的星星也包括窗户边缘的星星。现在，要你求出调整窗户位置后能看到星星的亮度之和最大值。"
        )
        print(" ")
        print("输入格式")
        print(" ")
        print("一行 N,WN,W，分别代表星星的数量和窗户的宽度")
        print("余下 NN 行，输入 X_i和 B_i，代表星星的坐标和亮度")
        print(" ")
        print("输出格式")
        print(" ")
        print("一个数字，代表能看到星星的最大亮度和")
        print(" ")
        print("输入输出样例")
        print("输入#1      输出#1")
        print(" 6 3         16")
        print(" 1 2")
        print(" 2 4")
        print(" 3 8")
        print(" 4 4")
        print(" 5 2")
        print(" 1000 1")
        print(" ")
        print("提交代码(1)")
        print("返回题目列表(2)")
        fh4 = int(input("你的选择？"))
        if fh4 == 1:
            print("")
            self.yuyan('P3353')
            print(" ")
            print("返回题目（1）")
            print("返回题目列表（2）")
            p3353pcfh = int(input("你的选择？"))
            if p3353pcfh == 1:
                problems.p3353()
            if p3353pcfh == 2:
                problems.tiku()
        if fh4 == 2:
            problems.tiku()

    def p3353pingceji(self):
        print(
            "#1              #2             #3              #4               #5"
        )
        time.sleep(3)
        print("")
        print(
            "    AC               AC               AC              AC              AC"
        )
        print("")
        print(
            "8ms/548.00KB    22ms/832.00KB  22ms/952.00KB   22ms/880.00KB    19ms/944.00KB"
        )
        print(" ")
        print(
            "#6              #7             #8              #9               #10"
        )
        time.sleep(2)
        print("")
        print(
            "     AC               AC             AC              AC               AC"
        )
        print("")
        print(
            "19ms/1.01.MB    19ms/1016.00KB 19ms/828.00KB   19ms/1016.00KB   19ms/1.02MB"
        )

    def scanf(self):
        x = 0
        y = str(input())
        x += 1
        while y != '交付评测':
            y = str(input())
            x += 1
        return x

    def pingce(self, s):
        print("")
        print("温馨提示：")
        print("在代码的最后输入“交付评测”")
        print("")
        if s == 'P1001':
            if problems.scanf() < 8:
                print("?!?!?!?!?!?!?!?")
                time.sleep(0.5)
                cnt = 0
                print(
                    "#1             #2             #3             #4             #5"
                )
                time.sleep(1.5)
                print("")
                print(
                    "    WA               WA             WA            WA              WA"
                )
                print("")
                print(
                    "  0ms/0KB       2ms/504.00KB   2ms/504.00KB     0ms/0KB      2ms/504.00KB"
                )
            else:
                problems.p1001pingceji()

        elif s == 'P3353':
            if problems.scanf() < 8:
                print("?!?!?!?!?!?!?!?")
                time.sleep(0.5)
                print(
                    "#1              #2               #3              #4              #5"
                )
                time.sleep(3)
                print("")
                print(
                    "    WA               WA               WA              WA              WA"
                )
                print("")
                print(
                    "8ms/548.00KB    22ms/832.00KB  22ms/952.00KB   22ms/880.00KB    19ms/944.00KB"
                )
                print(" ")
                print(
                    "#6               #7             #8              #9               #10"
                )
                time.sleep(2)
                print("")
                print(
                    "     WA               WA             WA              WA               WA"
                )
                print("")
                print(
                    "19ms/1.01.MB    19ms/1016.00KB 19ms/828.00KB   19ms/1016.00KB    19ms/1.02MB"
                )
            else:
                problems.p3353pingceji()

    def yuyan(self, s):
        print("")
        print("请输入语言")
        print("(1)C++")
        print("(2)C")
        print("(3)Python")
        print("(4)Pascal")
        print("(5)文言")
        yy = int(input("你的选择："))
        problems.pingce(s)

    def tiaoti(self):
        problem_number = 2
        print("欢迎进入跳题系统")
        tiaoti = str(input("请您输入题目编号:"))
        if tiaoti == "P1001":
            problems.p1001()
        elif tiaoti == 'P3353':
            problems.p3353()
        else:
            ytm = random.randint(1, problem_number)
            if ytm == 1:
                problems.p1001()
            elif ytm == 2:
                problems.p3553()


problems = Problems()  #好的我手残了 problems.


def yanzheng():
    yzm1 = random.randint(1, 9)
    yzm2 = random.randint(1, 9)
    yzm3 = random.randint(1, 9)
    yzm4 = random.randint(1, 9)
    print("验证码:^^&", str(yzm1), "    $*&*&$&%", str(yzm2), "#%&(&*#",
          str(yzm3), "#$^#&", str(yzm4))
    print("输入验证码（只输入数字）：", end=' ')
    y = str(input())
    if (str)(yzm1 * 1000 + yzm2 * 100 + yzm3 * 10 + yzm4) != y:
        print("")
        print("验证码错误0ДQ，你不会是人机吧!!!")
        print(" ")
        print("。", end=' ')
        time.sleep(0.5)
        print("。", end=' ')
        time.sleep(0.5)
        print("。", end=' ')
        time.sleep(0.5)
        print("")
        print("重新输入")
        print("。", end=' ')
        time.sleep(0.5)
        print("。", end=' ')
        time.sleep(0.5)
        print("。", end=' ')
        print("")
        time.sleep(0.5)
        yanzheng()


def gengxinrizhi():
    print("    版本更新日志    版本号:", banben)
    print("0.01:")
    print("   平台第一次搭建，当时还叫我谷")
    time.sleep(1)
    print("0.02:")
    print("   新增登录功能")
    time.sleep(1)
    print("0.03:")
    print("   优化登录界面，新增登录报错提醒")
    time.sleep(1)
    print("0.04:")
    print("   优化主界面，加入更多制作组元素，修复若干系统BUG")
    time.sleep(1)
    print("0.05:")
    print("   新增了功能列表")
    time.sleep(1)
    print("0.06:")
    print("   优化功能列表（虽然啥都没有）")
    time.sleep(1)
    print("0.07:")
    print("   新增了小游戏:猜数游戏")
    time.sleep(1)
    print("0.08:")
    print("   优化了猜数游戏，新增规则")
    time.sleep(1)
    print("0.09:")
    print("   优化了猜数游戏,新增结束反馈（《帝国的毁灭》版）")
    time.sleep(1)
    print("0.11:")
    print("   优化猜数游戏，修复若干BUG")
    time.sleep(1)
    print("0.12:")
    print("   1:新增了功能:计算阶乘")
    print("   2:新增更新日志")
    time.sleep(1)
    print("0.14:")
    print("   1:我谷 改名为 Actxt")
    print("   2:增加返回界面功能")
    time.sleep(1)
    print("0.16:")
    print("   新增猜数游戏半路退出功能")
    time.sleep(1)
    print("0.17:")
    print("   优化更新日志视觉效果，修复若干BUG")
    time.sleep(1)
    print("0.18:")
    print("   增加1.37版本之前的日志（累啊!）")
    time.sleep(1)
    print("0.19:")
    print("   新增功能：更新日志(也就是说可以在功能列表再次查看了）")
    time.sleep(1)
    print("0.20:")
    print("   新增wang抑云系统")
    time.sleep(1)
    print("0.22:")
    print("   优化功能：更新日志，修复若干BUG")
    time.sleep(1)
    print("0.25:")
    print("   修复系统BUG，更改部分系统结构")
    time.sleep(1)
    print("0.27:")
    print("   修复猜数游戏若干BUG，更改部分游戏结构")
    time.sleep(1)
    print("0.30:")
    print("   大更新：新增题库，它来啦！")
    time.sleep(1)
    print("0.32:")
    print("   1:增加题目：在她窗外闪耀的星星。")
    print("   2:优化部分系统结构")
    time.sleep(1)
    print("0.35:")
    print("   大更新：新增打卡系统，处处有惊喜！")
    time.sleep(1)
    print("0.37:")
    print("   1:新增题目：A+B问题。")
    print("   2:优化题库，优化展示")
    time.sleep(1)
    print("0.41:")
    print("   1:修复注册时闰月显示“小”的错误")
    print("   2:加入运势：中吉")
    print("   3:修复运势为“大凶”时打卡结果不对齐的BUG")
    print("   4:新增功能：跳题")
    print(" ")
    time.sleep(1)
    print("特殊版本：5.21:")
    print("   1:更新版本：盖亚。（你相信光吗）")
    print("   2:优化大厅标语")
    print("")
    time.sleep(1)
    print("0.42")
    print("   移除寄语系统")
    print("")
    print("_______________________________________")
    print("回车继续......")
    print(" ")
    xxsadsa = str(input())


def zhujiemian():
    print(" ")
    biaoti()
    print(" ")
    print(" ")
    print("登录输1，注册输2")
    key1 = "Actxt102"
    key2 = "*********"
    keyz1 = "zhang_z_d"
    keyz2 = "*********"
    xz1 = int(input("你的选择？"))
    if xz1 == 2:
        zcyhm = str(input("用户名："))
        zcmm = str(input("密码:"))
        yanzheng()
        print(" ")
        if xz1 == 2:
            print("        (^_^)ノ注册成功＼(-o- ) ")
            print("ヽ(???。)*-*好久不见*-*(。???)ノ ")
            print("          欢迎进入Actxt平台")
            print(" ")
            print(" ")
            biaoti()
            print(" ")
            print("         欢迎回来,", zcyhm)
            tian = dt.datetime.now().strftime('%d')
            yue = dt.datetime.now().strftime('%m')
            zhouji = dt.datetime.now().strftime('%u')
            daxiao = '小'
            if yue == '1' or yue == '3' or yue == '5' or yue == '7' or yue == '8' or yue == '10' or yue == '12':
                daxiao = '大'
            print("          ", yue, "   星")
            print("           月", tian, "期")
            print("          ", daxiao, "  ", zhouji)
            dakazc = int(input("输入1打卡"))
            if dakazc == 1:
                clock.laohuangli()
                zcjz = int(input("输入1进入主站"))
                if zcjz == 1:
                    gongnengliebiao()
    else:
        yhm = str(input("用户名:"))
        mm = str(input("密码:"))
        yzm1 = random.randint(1, 9)
        yzm2 = random.randint(1, 9)
        yzm3 = random.randint(1, 9)
        yzm4 = random.randint(1, 9)
        yanzheng()
        print("_____________________________________")

        if yhm == key1 and mm == key2:
            print("          登录成功")
            print("  欢迎主编进入Actxt平台")
            print(" ")
            print(" ")
            biaoti()
            print(" ")
            print("         欢迎,", yhm, "主编审阅")
            tian = dt.datetime.now().strftime('%d')
            yue = dt.datetime.now().strftime('%m')
            zhouji = dt.datetime.now().strftime('%u')
            daxiao = '小'
            if yue == '1' or yue == '3' or yue == '5' or yue == '7' or yue == '8' or yue == '10' or yue == '12':
                daxiao = '大'
            print("          ", yue, "   星")
            print("           月", tian, "期")
            print("          ", daxiao, "  ", zhouji)
            dakadl = int(input("输入1打卡"))
            if dakadl == 1:
                print("叮~~...")
                print("。", end=' ')
                time.sleep(0.5)
                print("。", end=' ')
                time.sleep(0.5)
                print("。")
                time.sleep(0.5)
                print("遭受主编权限介入，程序无法运行")
                print("。", end=' ')
                time.sleep(0.5)
                print("。", end=' ')
                time.sleep(0.5)
                print("。", end=' ')
                time.sleep(0.5)
                print("恭迎主编：")
                print("")
                clock.laohuangli_zhubian()
                dljz = int(input("输入1进入主站"))
                if dljz == 1:
                    gongnengliebiao()
        elif yhm == keyz1 and mm == keyz2:
            print("          登录成功")
            print("    欢迎小编进入Actxt平台")
            print(" ")
            print(" ")
            biaoti()
            print(" ")
            print("         欢迎,", yhm, "小编回来")
            tian = dt.datetime.now().strftime('%d')
            yue = dt.datetime.now().strftime('%m')
            zhouji = dt.datetime.now().strftime('%u')
            daxiao = '小'
            if yue == '1' or yue == '3' or yue == '5' or yue == '7' or yue == '8' or yue == '10' or yue == '12':
                daxiao = '大'
            print("          ", yue, "   星")
            print("           月", tian, "期")
            print("          ", daxiao, "  ", zhouji)
            dakadl = int(input("输入1打卡"))
            if dakadl == 1:
                clock.laohuangli()
                print("")
                dljz = int(input("输入1进入主站"))
                if dljz == 1:
                    gongnengliebiao()

        else:
            print("好像哪里不对…")
            print("")
            if yhm != key1 or yhm != keyz1:
                print(" 用户名错误")
                print("")
            if mm != key2 or yhm != keyz2:
                print("   密码错误")
                print("")
            if (yhm != key1 and yhm != keyz1) or (mm != key2 and yhm != keyz2):
                print("脑瓜子嗡嗡的，全错了")
                print(" ")
            fh3 = int(input("输入1返回主界面。"))
            if fh3 == 1:
                zhujiemian()


biaoti()

gengxinrizhi()

zhujiemian()