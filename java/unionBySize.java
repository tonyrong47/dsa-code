import java.util.Arrays;

public class UnionBySize {
    private int parent[];
    private int size[];

    UnionBySize(int n){
        parent = new int[n];
        size = new int[n];

        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
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
            if(size[rootX] > size[rootY]){
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }else{
                parent[rootX] = rootY;
                size[rootY] = size[rootX];
            }
        }
    }

    public boolean isConnected(int x, int y){
        return find(x) == find(y);
    }

    public void status(){
        System.out.println("parent"+Arrays.toString(parent));
        System.out.println("  size"+Arrays.toString(size));
    }

    public static void main(String []args){
        UnionBySize uf = new UnionBySize(8);

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
