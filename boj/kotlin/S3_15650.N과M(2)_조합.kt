fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val (N,M) = br.readLine().split(' ').map{it.toInt()}
    val comb=Array(M){it+1}
    var target:Int
    while(true){
        bw.write(comb.joinToString(" ")+"\n")
        target=comb.lastIndex
        while(target>=0 && comb[target]==N+target-M+1) target--
        if(target==-1) break
        comb[target]++
        for(idx in target+1 until M) comb[idx]=comb[idx-1]+1
    }
    bw.close()
}