class Solution {
    fun solution(lottos: IntArray, win_nums: IntArray): IntArray {
        val zeroNum = lottos.filter{it==0}.size
        val correctNum = lottos.filter{win_nums.contains(it)}.size
        return intArrayOf((7-zeroNum-correctNum).coerceAtMost(6),(7-correctNum).coerceAtMost(6))
    }
}