def work():
    a = input().split()
    ans = 0
    for x in a:
        ans += float(x)
    print("%.5f" % ans)


if __name__ == "__main__":
    work()
