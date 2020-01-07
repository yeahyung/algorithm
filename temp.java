package algorithm;

import java.io.*;
import java.util.*;

class data1{
    int x, y;
    public data1(int x,int y) {
        this.x = x;
        this.y = y;
    }
}

public class temp {
    static int[][] map;
    static boolean[][] visited;
    static int n, m, total=0;
    static ArrayList<Integer> list = new ArrayList<Integer>();
    static int[][] dir ={{-1,0},{1,0},{0,-1},{0,1}};
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer((br.readLine()));
        n = Integer.parseInt(st.nextToken());

        map = new int[n][n];
        visited = new boolean[n][n];

        for(int i=0;i<n;i++){
            String line;
            line = br.readLine();
            for(int j=0;j<n;j++){
                map[i][j] = line.charAt(j)-'0';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map[i][j]!=0)
                    bfs(i,j);
            }
        }
        System.out.println(list.size());
        Collections.sort(list);
        for(Integer temp :list)
            System.out.println(temp);
        br.close();
    }

    public static boolean isRange(int x,int y){
        if(x>=0 && x<n && y>=0 && y<n)
            return true;
        return false;
    }

    public static void bfs(int xx, int yy){
        Queue<data1> q = new LinkedList<data1>();
        q.add(new data1(xx,yy));

        int count=0;

        while(!q.isEmpty()){
            data1 front = q.remove();
            int x = front.x;
            int y = front.y;

            map[x][y]=0;
            count++;

            for(int i=0;i<4;i++){
                int tempX = x + dir[i][0];
                int tempY = y + dir[i][1];
                if(!isRange(tempX,tempY))
                    continue;
                if(map[tempX][tempY]!=0){
                    map[tempX][tempY]=0;
                    q.add(new data1(tempX,tempY));
                }
            }
        }
        list.add(count);
    }
}
