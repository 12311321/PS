import kotlin.math.abs

fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    val (N,V) = br.readLine().split(' ').map{it.toInt()}
    val arr = br.readLine().split(' ').map{it.toInt()}

    var ans=N
    for(i in 0 until N) for(j in i+1 until N){
       if(abs(arr[i]-arr[j])>=V){
           ans=ans.coerceAtMost((i+3)/2+(j-i+1)/2)
       }
    }
    println(ans)
}