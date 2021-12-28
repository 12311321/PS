import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashSet

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val N = br.readLine().toInt()
    val M = br.readLine().toInt()
    val adjList = Array(N) { ArrayList<Int>() }
    val par = Array(N) { it }
    val d = Array(N) { 0 }
    val destSet=HashSet<Int>()
    val queue: Queue<Int> = LinkedList()
    fun find(node: Int): Int {
        if (par[node] != node) {
            par[node] = find(par[node])
        }
        return par[node]
    }

    fun union(a: Int, b: Int) {
        val pa = find(a)
        val pb = find(b)
        if (pa == pb) return
        if (d[pa] == d[pb]) {
            par[pb] = pa
            d[pa]++
        } else if (d[pa] > d[pb]) par[pb] = pa
        else par[pa] = pb
    }

    repeat(N) {s->
        br.readLine().split(' ').map{it.toInt()}.forEachIndexed{e,b->
            if(b==1){
                adjList[s].add(e)
                adjList[e].add(s)
            }
        }
    }

    br.readLine().split(' ').map{it.toInt()}.forEach{destSet.add(it-1)}
    for(s in 0 until N){
        if(find(s)!=s) continue
        queue.add(s)
        while(queue.isNotEmpty()){
            val now=queue.poll()
            for(dest in adjList[now]){
                if(find(dest)!=dest) continue
                union(s,dest)
                queue.add(dest)
            }
        }
    }

    var p=-1
    var flag=true
    destSet.forEach{
        if(p==-1) p=find(it)
        else{
            flag=flag and (p==find(it))
        }
    }

    bw.write((if(flag)"YES" else "NO") + "\n")
    bw.close()
}