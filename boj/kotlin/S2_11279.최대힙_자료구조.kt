import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    class Heap(private val comparator: (Int, Int) -> Boolean) {
        val heap = ArrayList<Int>()

        fun insert(data: Int) {
            heap.add(data)
            upHeap(heap.lastIndex)
        }

        fun poll(): Int {
            if (heap.isEmpty()) return 0
            val ret = heap.first()
            heap[0] = heap.last()
            heap.removeLast()
            downHeap(0)
            return ret
        }

        private fun upHeap(idx: Int) {
            if (idx == 0) return
            if (comparator(heap[idx], heap[(idx - 1) / 2])) {
                swap(idx, (idx - 1) / 2)
                upHeap((idx - 1) / 2)
            }
        }

        private fun downHeap(idx: Int) {
            if (idx * 2 + 1 > heap.lastIndex) return
            if (idx * 2 + 1 == heap.lastIndex) {
                if (!comparator(heap[idx], heap[idx * 2 + 1])) swap(idx, idx * 2 + 1)
            } else {
                val target = if (comparator(heap[idx * 2 + 1], heap[idx * 2 + 2])) idx * 2 + 1 else idx * 2 + 2
                if (!comparator(heap[idx], heap[target])) {
                    swap(idx, target)
                    downHeap(target)
                }
            }
        }

        private fun swap(s: Int, e: Int) {
            val temp = heap[s]
            heap[s] = heap[e]
            heap[e] = temp
        }
    }

    val minHeap = Heap { a, b -> a > b }

    repeat(br.readLine().toInt()) {
        minHeap.run {
            val input = br.readLine().toInt()
            if (input == 0) bw.write("${poll()}\n")
            else insert(input)
        }
    }
    bw.flush()
}

