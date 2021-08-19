import java.io.*
data class Pos(var r:Int, var c:Int){
    operator fun plus(a:Pos):Pos{
        return Pos(this.r+a.r,this.c+a.c)
    }
}
val dir=arrayOf(Pos(0,1),Pos(-1,0),Pos(0,-1),Pos(1,0))

fun main(){
    val br= BufferedReader(InputStreamReader(System.`in`))
    val bw= BufferedWriter(OutputStreamWriter(System.out))
    val (N,M,x,y)=br.readLine().split(' ').map{it.toInt()}
    val map=Array(N){CharArray(M){' '} }
    for(i in 0..N-1){
        map[i]=br.readLine().toCharArray()
    }


    val mirrorPos=ArrayList<Pos>()
    for(i in 0..N-1){
        for(j in 0..M-1){
            if(map[i][j]=='?') mirrorPos.add(Pos(i,j))
        }
    }
    val arr=Array<Int>(mirrorPos.size){0}
    var ans=0
    val s=getPos(x,N,M)
    val e=getPos(y,N,M)
    while(true){
        if(search(arr,map,mirrorPos,s,e,N,M))   ans++


        var p=mirrorPos.size-1
        while(p>=0 && arr[p]==2){
            arr[p]=0
            p--
        }
        if(p==-1) break
        arr[p]++
    }


    bw.write((ans%10007).toString()+"\n")
    bw.flush()


}
fun getPos(a:Int,N:Int,M:Int):Pos{
    when{
        (a<=M)->{
            return Pos(-1,a-1)
        }
        (M+1<=a && a<=M+N)->{
            return Pos(a-M-1,-1)
        }
        (M+N+1<=a && a<=M+N*2)->{
            return Pos(a-M-N-1,M)
        }
        else->{
            return Pos(N,a-M-2*N-1)
        }
    }
}
fun search(arr:Array<Int>,map:Array<CharArray>,mirrorPos:ArrayList<Pos>,s:Pos,e:Pos,N:Int,M:Int):Boolean{
    for(i in 0..arr.size-1){
        when(arr[i]){
            0->{
                map[mirrorPos[i].r][mirrorPos[i].c]='.'
            }
            1->{
                map[mirrorPos[i].r][mirrorPos[i].c]='/'
            }
            2->{
                map[mirrorPos[i].r][mirrorPos[i].c]='\\'
            }

        }
    }

    var d=when{
        s.r==-1->3
        s.r==N->1
        s.c==-1->0
        else->2
    }
    var pos=s+dir[d]
    for(i in 0..4*N*M){
        when(map[pos.r][pos.c]){
            '/'->{
                when(d%2){
                    0->d++
                    1->d--
                }
            }
            '\\'-> {
               when(d%2){
                   0->d=(4+d-1)%4
                   1->d=(d+1)%4
               }
            }
        }
        pos+=dir[d]

        if(pos.r==e.r && pos.c==e.c) return true
        if(pos.r<0 || pos.r>=N || pos.c<0 || pos.c>=M) return false
    }
    return false
}