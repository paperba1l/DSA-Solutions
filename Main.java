import java.util.*;
import java.lang.*;
import java.io.*;
 
class Main {
    static Long[] s = new Long[2];
    static Long xorshift128plus() {
        Long x = s[0];
        final Long y = s[1];
        x ^= x << 23;
        s[1] = x ^ y ^ (x >>> 17) ^ (y >>> 26);
        return s[0] = y;
    }
    
    static final int MX = 1000;
    static int[][] C = new int[MX][MX];
    static int[][] H = new int[MX][MX];
    
    static FastReader in;
    public static void main(String[] args) {
        in = new FastReader();
        int T = ni();
        for (int t = 0; t < T; t++) {
            int n = ni();
            Graph g = new Graph(n);
            int Cmax = ni();
            int Hmax = ni();
            for (int i = 0; i < n; i++) {
                C[i][i] = 0;
                String seed1 = n();
                String seed2 = n();
                s[0] = Long.parseUnsignedLong(seed1);
                s[1] = Long.parseUnsignedLong(seed2);
                for (int j = i + 1; j < n; j++) {
                    Long value = Long.remainderUnsigned(xorshift128plus(), Cmax + 1);
                    C[i][j] = C[j][i] = Math.toIntExact(value);
                    g.addEdge(i, j);
                }
            }
            
            for (int i = 0; i < n; i++) {
                String seed1 = n();
                String seed2 = n();
                s[0] = Long.parseUnsignedLong(seed1);
                s[1] = Long.parseUnsignedLong(seed2);
                for (int j = 0; j < n; j++) {
    				Long value = Long.remainderUnsigned(xorshift128plus(), Hmax + 1);
    				H[i][j] = Math.toIntExact(value);
    			}
            }
            g.run();
        }
    }
    
    static class Edge{
       int src,dest;
       public Edge(int u, int v){
           src = u;
           dest = v;
       }
    }
    
    static class Subset{
        int parent, rank;
        public Subset(int p){
            parent = p;
            rank = 0;
        }
    }
    static class Graph{
        int V, E;
        Edge edge[];
        int ePoint = 0;
        int RUN = 1000;
        public Graph(int N){
           V = N;
           E = (N*N-N)/2;
           edge = new Edge[E];
        }
        
        public void addEdge(int u, int v){
            edge[ePoint++] = new Edge(u,v);
        }
        
        int find(Subset subsets[], int i){
            if (subsets[i].parent != i)subsets[i].parent = find(subsets, subsets[i].parent);
            return subsets[i].parent;
        }
        
        void union(Subset subsets[], int x, int y){
            int xroot = find(subsets, x);
            int yroot = find(subsets, y);
            if (subsets[xroot].rank < subsets[yroot].rank)
                subsets[xroot].parent = yroot;
            else if (subsets[xroot].rank > subsets[yroot].rank)
                subsets[yroot].parent = xroot;
            else{
                subsets[yroot].parent = xroot;
                subsets[xroot].rank++;
            }
        }
        
        void run(){
            int t = 1;
            int N = V*V;
            long MIN = Long.MAX_VALUE;
            StringBuilder base = new StringBuilder("");
            for(int i = 0; i<N; i++)base.append("0");
            
            StringBuilder out = new StringBuilder("");
            while(t++<=RUN){
                Edge[] result = new Edge[V-1];
                int[] degree = new int[V];
                int e = 0;
                long cost = 0;
                Subset subsets[] = new Subset[V];
                for(int i=0; i<V; i++)subsets[i]=new Subset(i);
                while(e < 0.8*(V-1)){
                    int x = (int)((Math.random()*N)%N);
                    int u = x/V, v = x%V;
                    if(find(subsets, u) != find(subsets,v)){
                        result[e++] = new Edge(u,v);
                        cost += C[u][v];
                        degree[u]++;
                        degree[v]++;
                        union(subsets, u, v);
                    }
                }
                int x = ((int)(Math.random()*N)%N);
                for(int j = x; e< V-1 ;j++){
                    if(j>=N)j %= N;
                    int u = j/V, v = j%V;
                    if(find(subsets, u) != find(subsets, v)){
                        result[e++] = new Edge(u,v);
                        cost += C[u][v];
                        degree[u]++;
                        degree[v]++;
                        union(subsets, u,v);
                    }
                }
                for(int i = 0; i< V; i++)cost += H[i][degree[i]];
                if(cost < MIN){
                    MIN = cost;
                    out = new StringBuilder(base);
                    for(Edge e1:result){
                        int u = e1.src, v = e1.dest;
                        out.setCharAt(u*V+v, '1');
                        out.setCharAt(v*V+u, '1');
                    }
                }
            }
            for(int i = 0; i<V; i++){
                pn(out.substring(i*V, i*V+V));
            }
        }
    }
    
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
    
        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }
    
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
    
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
    
    static void p(Object o){
        System.out.print(o);
    }
    
    static void pn(Object o){
        System.out.println(o);
    }
    
    static String n(){
        return in.next();
    }
    
    static String nln(){
        return in.nextLine();
    }
    
    static int ni(){
        return Integer.parseInt(in.next());
    }
    
    static long nl(){
        return Long.parseLong(in.next());
    }
    
    static double nd(){
        return Double.parseDouble(in.next());
    }
} 