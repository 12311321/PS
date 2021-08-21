
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*
import kotlin.collections.ArrayList
lateinit var visit:Array<Int>
lateinit var adjlist:Array<ArrayList<Int>>
var ct=0
fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    val (c,l)=br.readLine().split(' ').map{it.toInt()}
    adjlist=Array(c){ArrayList<Int>()}
    for(i in 0..l-1){
        val (a,b)=br.readLine().split(' ').map{it.toInt()}
        adjlist[a].add(b)
        adjlist[b].add(a)
    }
    visit=Array(c){-1}
    val radius=ArrayList<Int>()
    var ans=0
    for(i in 0..c-1){
        if(visit[i]==-1){
            val diameter=getDiameter(i)
            ans=max(ans,diameter)
            radius.add((diameter+1)/2)
        }
    }

    radius.sortWith{a:Int,b:Int->when{
        a<b-> 1
        a>b-> -1
        else-> 0
    }}


    when(radius.size){
       1->{}
        2->ans=max(ans,radius[0]+radius[1]+1)
        else->{
            var v=radius[0]+radius[1]+1
            if(radius[0]==radius[1] && radius[0]==radius[2]){
                v++
            }
            ans=max(ans,v)

        }
    }
    bw.write("${ans}\n")
    bw.flush()
}
fun getDiameter(s:Int):Int{
    val a=getDiameterPoint(s)
    return getDiameterPoint(a.first).second
}
fun getDiameterPoint(s:Int):Pair<Int,Int>{
    ct++
    val q:Queue<Pair<Int,Int>> = LinkedList()
    var ret=Pair(s,0)
    visit[s]=ct
    q.add(Pair(s,0))
    while(q.isNotEmpty()){
        val t=q.poll()
        ret=t
        (adjlist[t.first]).forEach{
            if(visit[it]!=ct){
                visit[it]=ct
                q.add(Pair(it,t.second+1))
            }
        }
    }

    return ret

}

