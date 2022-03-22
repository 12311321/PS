fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val T=br.readLine().toInt()
    val N=br.readLine().toInt()
    val A= br.readLine().split(' ').map{it.toInt()}.toMutableList()
    val M=br.readLine().toInt()
    val B=br.readLine().split(' ').map{it.toInt()}.toMutableList()
    for(i in 1 until A.size){ A[i]+=A[i-1] }
    for(i in 1 until B.size){ B[i]+=B[i-1] }
    val aMap = HashMap<Int,Int>().apply{
        for(s in 0 until A.size) for(e in s until A.size){
            val key=A[e]-(if(s==0)0 else A[s-1])
            put(key,getOrDefault(key,0)+1)
        }
    }

    val bMap = HashMap<Int,Int>().apply{
        for(s in 0 until B.size) for(e in s until B.size){
            val key=B[e]-(if(s==0)0 else B[s-1])
            put(key,getOrDefault(key,0)+1)
        }
    }

    var ans=0L
    aMap.forEach{
        ans+=it.value.toLong()*bMap.getOrDefault(T-it.key,0)
    }
    println(ans)
}