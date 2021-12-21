import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*
import kotlin.collections.HashSet

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val map=Array(N+2){Array(M+2){0} }
    val meltSet=HashSet<Pair<Int,Int>>()
    val queue:Queue<Pair<Int,Int>> = LinkedList()
    val visit=Array(N+2){Array(M+2){false} }
    val dir=arrayOf(Pair(1,0),Pair(-1,0),Pair(0,1),Pair(0,-1))
    val isValidPos={r:Int,c:Int->r in 0 until N+2 && c in 0 until M+2}
    val reset={
        meltSet.clear()
        queue.clear()
        visit.forEach{ it.fill(false,0,M+2) }
    }
    var cnt=0
    repeat(N){r->
        br.readLine().split(' ').map{it.toInt()}.forEachIndexed{c,n->
            map[r+1][c+1]=n
            cnt+=n
        }
    }
    val melt = {
        reset()
        visit[0][0]=true
        queue.add(Pair(0,0))
        while(queue.isNotEmpty()){
            val now=queue.poll()
            if(map[now.first][now.second]==1){
                meltSet.add(now)
                continue
            }
            for(d in dir){
                val nr=now.first+d.first
                val nc=now.second+d.second
                if(!isValidPos(nr,nc) || visit[nr][nc]) continue
                visit[nr][nc]=true
                queue.add(Pair(nr,nc))
            }
        }
        cnt-=meltSet.size
        meltSet.forEach{
            map[it.first][it.second]=0
        }
    }

    var ansTime=0
    var ansNum=0
    while(cnt>0){
        ansNum=cnt
        melt()
        ansTime++
    }

    bw.write("$ansTime\n$ansNum\n")
    bw.close()
}

/*
100 100
모든 치즈가 꽉 차있을 때
ans : 50 4


1 1
1
ans : 1 1

4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
ans : 0 0

4 4
1 0 1 0
0 1 0 1
1 0 1 0
0 1 0 1
ans : 1 8

4 4
0 1 1 0
0 1 1 0
0 1 1 0
0 1 1 0
ans : 1 8

5 5
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
ans : 1 1

5 5
0 0 0 0 0
0 1 1 1 0
0 1 1 1 0
0 1 1 1 0
0 0 0 0 0
ans : 2 1

5 5
0 1 1 1 0
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
0 1 1 1 0
ans : 3 1

5 5
0 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
0 1 1 1 0
ans : 3 1
 */