import java.util.*

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val q = LinkedList<Int>()
    repeat(br.readLine().toInt()){tc->
        val (N,K) = br.readLine().split(' ').map{it.toInt()}
        val D = br.readLine().split(' ').map{it.toInt()}
        val complete = Array(N){0}
        val inDeg = Array(N){0}
        val adjList = Array(N){ArrayList<Int>()}
        repeat(K){
            br.readLine().split(' ').map{it.toInt()-1}.run{
                adjList[get(0)].add(get(1))
                inDeg[get(1)]++
            }
        }

        for(i in 0 until N){
            if(inDeg[i]==0){
                q.add(i)
                complete[i]=D[i]
            }
        }

        while(q.isNotEmpty()){
            val now = q.poll()
            for(next in adjList[now]){
                complete[next] = maxOf(complete[next],complete[now])
                inDeg[next]--
                if(inDeg[next]==0){
                    complete[next]+=D[next]
                    q.push(next)
                }
            }
        }
        bw.write("${complete[br.readLine().toInt()-1]}\n")
    }
    bw.close()
}