import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val N = br.readLine().toInt()

    data class Rect(val x1: Int, val y1: Int, val x2: Int, val y2: Int)

    // x축 시작점을 기준으로 정렬
    val rectArr = Array(N) {
        br.readLine().split(' ').map { it.toInt() }.run {
            Rect(get(0), get(1), get(2), get(3))
        }
    }.apply {
        sortWith { a, b ->
            when {
                a.x1 > b.x1 -> 1
                a.x1 < b.x1 -> -1
                else -> 0
            }
        }
    }


    // x축 끝점을 기준으로 정렬
    val pq = PriorityQueue<Rect> { a, b ->
        when {
            a.x2 > b.x2 -> 1
            a.x2 < b.x2 -> -1
            else -> 0
        }
    }

    // y축 시작점 기준으로 정렬
    val nowList = ArrayList<Rect>()

    // ArrayList에 항상 y1의 오름차순으로 정렬된 상태 유지
    val addNowList = { rect: Rect ->
        if (nowList.isEmpty() || nowList.last().y1 <= rect.y1) nowList.add(rect)
        else{
            for(idx in nowList.indices){
                if(nowList[idx].y1>rect.y1){
                    nowList.add(idx,rect)
                    break
                }
            }
        }
    }

    val removeNowList={rect:Rect->
        for(idx in nowList.indices){
            if(nowList[idx]==rect) {
                nowList.removeAt(idx)
                break
            }
        }
    }

    val getHeight={
        var h=0L
        if(nowList.isNotEmpty()){
            var lastYPos=nowList[0].y2
            h+=lastYPos-nowList[0].y1
            for(idx in 1 until nowList.size){
                if(nowList[idx].y1>lastYPos){
                    h+=nowList[idx].y2-nowList[idx].y1
                    lastYPos=nowList[idx].y2
                }else if(nowList[idx].y2>lastYPos){
                    h+=nowList[idx].y2-lastYPos
                    lastYPos=nowList[idx].y2
                }

            }
        }
        h
    }

    var ans=0L
    var lastX=0
    for (rect in rectArr) {
        while(pq.isNotEmpty() && pq.peek().x2<rect.x1){
            val r=pq.poll()
            ans+=getHeight()*(r.x2-lastX)
            lastX=r.x2
            removeNowList(r)
        }

        ans+=getHeight()*(rect.x1-lastX)
        pq.add(rect)
        addNowList(rect)
        lastX=rect.x1
    }
    while(pq.isNotEmpty()){
        val r=pq.poll()
        ans+=getHeight()*(r.x2-lastX)
        lastX=r.x2
        removeNowList(r)
    }
    bw.write("$ans\n")
    bw.close()
}