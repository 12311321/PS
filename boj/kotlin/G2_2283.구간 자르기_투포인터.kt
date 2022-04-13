fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val MAX_POS = 1000000

    val (N,K) = br.readLine().split(' ').map{it.toInt()}
    val pos = Array(MAX_POS+1){0}
    repeat(N){
        br.readLine().split(' ').map{it.toInt()}.run{
            pos[get(0)]--
            pos[get(1)]++
        }
    }
    for(i in MAX_POS-1 downTo(0)) pos[i]+=pos[i+1]

    var s=0
    var k=0
    for(i in 1..MAX_POS){
        k+=pos[i]
        while(k>K)k-=pos[++s]
        if(k==K){
            println("$s $i")
            return
        }
    }
    println("0 0")

}