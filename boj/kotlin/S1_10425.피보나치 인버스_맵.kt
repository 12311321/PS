fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val fMap = HashMap<Long, Int>()
    val mod=10000000000000000L
    val pre=Array(2){0L}
    pre[1]=1L
    for(i in 2..100000){
        val now=(pre[0]+pre[1])%mod
        fMap[now]=i
        pre[0]=pre[1]
        pre[1]=now
    }
    repeat(br.readLine().toInt()) {
        val lastNum=br.readLine().run{substring((lastIndex-16).coerceAtLeast(0)).toLong()%mod}
        bw.write("${fMap[lastNum]}\n")
    }
    bw.close()
}