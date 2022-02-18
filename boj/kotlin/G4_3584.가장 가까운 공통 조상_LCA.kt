import kotlin.collections.ArrayList

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    data class Node(var d:Int, var par:Int, val children:ArrayList<Int> = ArrayList())

    fun dfs(pos:Int, depth:Int, nodes:Array<Node>){
        nodes[pos].d=depth
        for(child in nodes[pos].children) dfs(child,depth+1,nodes)
    }

    repeat(br.readLine().toInt()) {
        val N = br.readLine().toInt()
        val nodes=Array(N){Node(-1,-1)}

        repeat(N-1){
            br.readLine().split(' ').map{it.toInt()-1}.run{
                nodes[get(0)].children.add(get(1))
                nodes[get(1)].par=get(0)
            }
        }
        for(idx in nodes.indices){
            if(nodes[idx].par==-1){
                dfs(idx,0,nodes)
                break
            }
        }

        var(a,b) = br.readLine().split(' ').map{it.toInt()-1}
        while(a!=b){
            if(nodes[a].d<nodes[b].d) b=nodes[b].par
            else a=nodes[a].par
        }
        bw.write("${a+1}\n")
    }
    bw.close()
}