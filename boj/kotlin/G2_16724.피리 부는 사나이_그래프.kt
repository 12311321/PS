fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val board = Array(N) { br.readLine() }
    val check = Array(N){Array(M){-1} }
    val dir = hashMapOf('U' to (-1 to 0), 'D' to (1 to 0), 'L' to (0 to -1), 'R' to (0 to 1))
    var ans = 0
    for (r in 0 until N) for (c in 0 until M) {

        if (check[r][c] == -1) {
            val k =r*M+c
            check[r][c]=k
            var nowPos = r to c
            while (true) {
                val d = dir[board[nowPos.first][nowPos.second]]!!
                val nextPos = nowPos.first + d.first to nowPos.second + d.second
                if(nextPos.run{check[first][second]}==-1){
                    nextPos.run{check[first][second]=k}
                    nowPos=nextPos
                }else{
                    if(nextPos.run{check[first][second]}==k) ans++
                    break
                }
            }
        }
    }
    println(ans)
}