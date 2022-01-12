import java.util.*

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val dir=arrayOf(1 to 0, -1 to 0, 0 to 1 , 0 to -1)
    val str=Array(12){br.readLine().toCharArray()}
    val visit=Array(12){Array(6){-1} }
    val isValidPos={r:Int,c:Int->r in 0 until 12 && c in 0 until 6}
    val queue:Queue<Pair<Int,Int>> = LinkedList()
    val visitList=ArrayList<Pair<Int,Int>>()
    fun puyo(cnt:Int):Boolean{
        var ret=0
        for(r in 0 until 12) for(c in 0 until 6){
            if(visit[r][c]==cnt || str[r][c]=='.') continue
            queue.clear()
            visitList.clear()
            val color=str[r][c]
            queue.add(r to c)
            visit[r][c]=cnt
            visitList.add(r to c)
            while(queue.isNotEmpty()){
                val now=queue.poll()
                for(d in dir){
                    val nr=now.first+d.first
                    val nc=now.second+d.second
                    if(!isValidPos(nr,nc) || visit[nr][nc]==cnt || str[nr][nc]!=color) continue
                    visit[nr][nc]=cnt
                    queue.add(nr to nc)
                    visitList.add(nr to nc)
                }
            }
            if(visitList.size>=4){
                ret++
                visitList.forEach{ str[it.first][it.second]='.'}
            }

        }
        return ret>0
    }

    fun gravity(){
        for(c in 0 until 6){
            var target=11
            for(r in 11 downTo 0){
                if(str[r][c]!='.'){
                    val temp=str[r][c]
                    str[r][c]='.'
                    str[target--][c]=temp
                }
            }
        }
    }
    var cnt=0
    var ans=0
    while(true){
        if(!puyo(cnt++)) break
        else ans++

        gravity()

    }
    bw.write("$ans")
    bw.close()
}