





import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Math.*
import java.util.*


data class Edge(val e:Int, val d:Int)
fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    val (N,V,E)=br.readLine().split(' ').map{it.toInt()}
    val (A,B)=br.readLine().split(' ').map{it.toInt()}
    var str=br.readLine().split(' ')
    val H=Array(N){-1}

    for(i in 0..N-1){
        H[i]=str[i].toInt()-1
    }
    val adjlist=Array(V){ArrayList<Edge>()}
    val distA=Array(V){-1}
    val distB=Array(V){-1}
    for(i in 1..E){
        val(a,b,l)=br.readLine().split(' ').map{it.toInt()}
        adjlist[a-1].add(Edge(b-1,l))
        adjlist[b-1].add(Edge(a-1,l))
    }

    val pq=PriorityQueue{A:Edge,B:Edge->when{
        A.d<B.d->1
        A.d>B.d->-1
        else->0
    }}

    distA[A-1]=0
    pq.add(Edge(A-1,0))
    while(pq.isNotEmpty()){
        val t=pq.poll()
        if(t.d>distA[t.e]) continue

       for(i in 0..adjlist[t.e].size-1){
           val Edge=adjlist[t.e][i]
           if(distA[Edge.e]==-1 || distA[Edge.e]>distA[t.e]+Edge.d){
               distA[Edge.e]=distA[t.e]+Edge.d
               pq.add(Edge(Edge.e,distA[Edge.e]))
           }
       }

    }


    distB[B-1]=0
    pq.add(Edge(B-1,0))
    while(pq.isNotEmpty()){
        val t=pq.poll()
        if(t.d>distB[t.e]) continue

        for(i in 0..adjlist[t.e].size-1){
            val Edge=adjlist[t.e][i]
            if(distB[Edge.e]==-1 || distB[Edge.e]>distB[t.e]+Edge.d){
                distB[Edge.e]=distB[t.e]+Edge.d
                pq.add(Edge(Edge.e,distB[Edge.e]))
            }
        }

    }

    var ans=0
    for(i in H){
        ans+=distA[i]+distB[i]
    }
    bw.write(ans.toString()+"\n")
    bw.flush()
}

/*
TODO 반드시 제출언어 바꿔서 내기!!!!!!!!!!!!!
 */