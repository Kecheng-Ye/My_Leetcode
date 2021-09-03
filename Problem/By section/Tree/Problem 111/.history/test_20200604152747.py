'''
假设我们想要处理的 list 名字为 ’lst‘
这个lst数据里每一个抽屉都存着一个tuple, 每个tuple里都存着一个string的话


list以及tuple的基本查询操作 -> 假设我想获取这个lst这个数据里第1个抽屉里的数据的话, lst[0]会返回相对应数据
                            0十分重要！！！    在代码的世界里，无论list或者tuple都是从0开始计数的

在当前状况下，比如我们想获取 lst 第 i 个的 sql table 的名字的话
我们应当输入 lst[i - 1][0]
首先 lst[i - 1] 会让程序返回给我们这个lst第i个tuple对不对
然后我们想获取lst[i - 1]这个tuple里面的数据，因为我们知道这个tuple里面其实只存了一个string
所以lst[i - 1][0]会使得我们获得这个tuple里面的第一个也是唯一个数据
'''


# 接下来我们想要干的事情是不是将我们原本抽屉里一些我们不需要的东西不要掉
# 只存Market开头的table name么
# 实际实现这一功能的逻辑是不是
# 我们首先会新建一个list
# 然后我们通过循环原本的list中的每一个table name
# 当我们遇到table name的开头为Market的时候
# 我们将这个值存入我们之前新建的list
# 最后我们新建的list里面是不是只有我们想要的数据了呢


# 下面为详细实现代码
# lst为原list，也就是你代码里的Name

# 新建一个空的list
ans = []

# 对于lst里的每一个tuple
# 这是python里面循环lst的一个操作方式
# 每一次循环，我这个each_tuple变量都会不一样，直到这个lst我们查询完了
# 我就的循环就结束了
for each_tuple in lst:
    # 这里的indentation很重要
    # 代表着以下代码只有在循环内才会执行

    # 每个tuple里面都只存了一个string
    # 不懂看我最上面的注释
    table_name = each_tuple[0]
    
    # 如果我们当前查询的这个tuple里存的table name是以'MarketData'为开头的
    # str.startswith(_var_)这个函数是python里内置的string处理函数
    # 会帮我们判断str这个字符串是否以_var_这个变量为开头
    # 如果是则这个函数会返回True值，如果不是，则会返回False值
    # 对于if statement, 只有statement的值为true的时候, 才会执行if一下的代码
    if table_name.startswith('MarketData'):
        # 这里的indentation很重要
        # 代表着以下代码只有在if statement为true的情况下才会执行
        # ans.append(var)会将var这个变量加到ans这个list的最末尾
        # 所以这里就代表着，只有我们的table_name是以'MarketData'为开头时, 我们才会将table_name这个变量存到我们最终的list里面去
        ans.append(table_name)

# 这里的代码又跟一开始的for 循环那一条对齐了
# 说明我们已经出了循环了
# print一下ans来double check一下
# 实际情况中不需要
print(ans)



# 对于lst里的每一个tuple
# 这是python里面循环lst的另一种操作方式
# 首先len(lst)会返回这个lst的长度
# 然后range(number)会自动生产一个 [0 , 1, ..., number - 1]的list
# 所以相当于我们i变成 0, 1, ..., 直到number - 1这个值，然后循环就结束了
for i in range(len(lst)):
    # 这个就跟一开始注释上面说的一模一样了
    # 不会再去看一下最上面的注释
    table_name = lst[i][0]
    
    # 下面都一样了
    if table_name.startswith('MarketData'):
        ans.append(table_name)

# print一下ans来double check一下
# 实际情况中不需要
print(ans)