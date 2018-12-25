 git remote add origin https://github.com/PowderHan/code.git
 git fetch origin
 git merge origin/master

Git环境设置

    Linux创建SSH密钥：ssh-keygen
    将公钥加入到Github账户信息Account Settings->SSH Key（）：先 cd ~/.ssh,找不到可以用ls -al指令,之后用cat查看该文件（文件名是pub结尾，内容是ssh-rsa开头的）用vim或是vi指令也可以。
    测试验证是否成功：ssh -T git@github.com
    本地配置：
    git config --global user.name 'XXXX'
    git config --global user.email 'XXXX@gmail.com'

提交

    先新建本地仓库：git init
    添加文件到本地仓库：git add XX
    提交到本地库并备注，此时变更仍在本地git commit -m "first commit
    自动更新变化的文件：git commit -a
    增加一个远程服务器的别名：git remote add origin git@github.com:kkevinyang/spiders.git
    推送：git push -u origin master
    
    git push -u origin +master  


其他

若是推送到已有文件的仓库，则是最后输入：
git push -u XXXX master
注：
若是第一次同步用git push -u推送不出去，可以试试git push，或是
git config http.postBuffer 52428800
事例

    若是已有某文件夹已经同步过github了，之后往里面新增了文件，想要把它添加到github的库中，只需要三步即可：
        git add
        git commit -m “XXX”
        git push -u origin master
    新建仓库完整过程：
        cd到上传的文件夹内
        git add .
        git commit -m “First commit”
        git remote add origin https://github.com/kkevinyang/Guitarpa.git
        git push -u origin master
    已有的仓库同步过程：
        git remote add origin https://github.com/kkevinyang/Guitarpa.git
        git push -u origin master
    其他

# 创建一个版本库
git init
# 每次修改好了后，可以先将修改存入stage(快照/索引)中
git add <modified files>
# 修改了大量文件则使用下面这个命令批量存入
git add .
# 使用commit将快照/索引中的内容提交到版本库中
git commit -m "msg"
# 也可以将git add与git commit用一个指令完成
git commit -a -m "msg"
# 将本地的git档案与github(远程)上的同步
git push
# 将github(远程)的git档案与本地的同步(即更新本地端的repo)
git pull
# 例如,pull指令其实包含了fetch(將变更复制回來)以及merge(合并)操作
git pull git://github.com/tom/test.git

# 另外版本控制系統的branch功能也很有意思，若同时修改bug，又要加入新功能，可以fork出一个branch：一个专门修bug，一个专门加入新功能，等到稳定后再merge合并
git branch bug_fix # 建立branch，名为bug_fix
git checkout bug_fix # 切换到bug_fix
git checkout master #切换到主要的repo
git merge bug_fix #把bug_fix这个branch和现在的branch合并

# 若有remote的branch，想要查看并checkout
git branch -r # 查看远程branch
git checkout -b bug_fix_local bug_fix_remote #把本地端切换为远程的bug_fix_remote branch并命名为bug_fix_local

# 还有其它可以查看repo状态的工具
git log #可以查看每次commit的改变
git diff #可以查看最近一次改变的內容，加上参数可以看其它的改变并互相比较
git show #可以看某次的变更

# 若想知道目前工作树的状态，可以輸入
git status
--------------------- 
作者：kkevinyang 
来源：CSDN 
原文：https://blog.csdn.net/kkevinyang/article/details/52684913 
版权声明：本文为博主原创文章，转载请附上博文链接！
