import java.util.Arrays;

public class UnionByRank {
    private int parent[];
    private int rank[];

    UnionByRank(int n){
        parent = new int[n];
        rank = new int[n];

        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    public int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public void union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY){
            if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            }else if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            }else{
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    public boolean isConnected(int x, int y){
        return find(x) == find(y);
    }

    public void status(){
        System.out.println("parent"+Arrays.toString(parent));
        System.out.println("  rank"+Arrays.toString(rank));
    }

    public static void main(String []args){
        UnionByRank uf = new UnionByRank(8);

        uf.union(1,2);
        uf.union(2,3);
        uf.union(4,5);
        uf.union(6,7);
        uf.union(5,6);

        System.out.println(uf.isConnected(7,4));
        System.out.println(uf.isConnected(3, 6));

        uf.status();
    }
}