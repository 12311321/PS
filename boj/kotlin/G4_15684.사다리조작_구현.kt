fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()

    val (N, M, H) = br.readLine().split(' ').map { it.toInt() }
    val map = Array(H) { Array(N - 1) { false } }
    repeat(M) {
        br.readLine().split(' ').map { it.toInt() - 1 }.run { map[get(0)][get(1)] = true }
    }

    fun isCorrectPos(pos: Pair<Int,Int>): Boolean {
        if(map[pos.first][pos.second]) return false
        if(pos.second>0 && map[pos.first][pos.second-1]) return false
        if(pos.second<N-2 && map[pos.first][pos.second+1]) return false
        return true
    }

    fun play():Boolean{

        for(c in 0 until N){
            var pos=c
            for(r in 0 until H){
                if(pos>0 && map[r][pos-1]) pos -= 1
                else if(pos<N-1 && map[r][pos]) pos+=1
            }

            if(pos!=c) return false
        }
        return true
    }
    fun comb(n: Int, k: Int, comb: ArrayList<Int>): Boolean {
        if(comb.size==k) return play()

        val s=if(comb.isEmpty()) 0 else comb.last()+1
        for(i in s until n){
            val r=i/(N-1)
            val c=i%(N-1)
            if(isCorrectPos(Pair(r,c))){
                map[r][c]=true
                comb.add(i)
                if(comb(n,k,comb)) return true
                comb.removeLast()
                map[r][c]=false
            }
        }
        return false
    }

    var ans = -1
    for (i in 0..3) {
        if (comb(H * (N - 1), i, ArrayList())) {
            ans = i
            break
        }
    }
    bw.write("$ans\n")
    bw.close()
}