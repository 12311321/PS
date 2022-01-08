fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val dir = arrayOf(1 to 0, -1 to 0, 0 to 1, 0 to -1)

    val (R, C) = br.readLine().split(' ').map { it.toInt() }
    val map = Array(R) { br.readLine().split(' ').map { it.toInt() }.toTypedArray() }
    val dp = Array(R) { Array(C) { 0 } }

    val maxH=map.maxOf{it.maxOf{h->h}}
    val minH=map.minOf{it.minOf{h->h}}
    val sortedPos=Array(maxH-minH+1){ArrayList<Pair<Int,Int>>()}
    for(r in 0 until R) for(c in 0 until C){sortedPos[map[r][c]-minH].add(Pair(r,c))}

    val isValidPos={r:Int,c:Int->r in 0 until R && c in 0 until C}
    dp[0][0]=1
    sortedPos.apply{reverse()}.forEach{
        for(pos in it){
            for(d in dir){
                val nr=pos.first+d.first
                val nc=pos.second+d.second
                if(!isValidPos(nr,nc)) continue
                if(map[nr][nc]>=map[pos.first][pos.second]) continue
                dp[nr][nc]+=dp[pos.first][pos.second]
            }
        }
    }

    bw.write(dp[R-1][C-1].toString())
    bw.close()
}