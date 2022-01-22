fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val N = br.readLine().toInt()
    val arr = Array(N) { Array(N) { '*' } }
    fun go(r: Int, c: Int, sz: Int) {
        if(sz==1) return
        val nsz=sz/3
        for(nr in r+nsz until r+2*nsz) for(nc in c+nsz until c+2*nsz) arr[nr][nc]=' '
        for(nr in 0 until 3) for(nc in 0 until 3){
            if(nr==1 && nc==1) continue
            go(r+nsz*nr,c+nsz*nc,nsz)
        }
    }

    go(0, 0, N)
    println(StringBuilder("").apply {
        for (r in 0 until N){
            for (c in 0 until N){
                append(arr[r][c])
            }
            append("\n")
        }
    }.toString())
}