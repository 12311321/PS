fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()

    var (N,K)=br.readLine().split(' ').map{it.toInt()}
    val arr=Array(N){0}
    repeat(N){ arr[it]=br.readLine().toInt() }
    var ans=0
    for(i in arr.lastIndex downTo 0){
        ans+=K/arr[i]
        K%=arr[i]
    }
    bw.write("$ans")
    bw.close()
}