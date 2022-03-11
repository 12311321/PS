fun main(){
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val N=br.readLine().toInt()
    val ans = ArrayList<Int>()
    repeat(N){
        ans.add(it+1)
        ans.addAll(ans)
        ans.removeLast()
    }
    println("${ans.size}\n${ans.joinToString("\n")}\n$N\n")
}