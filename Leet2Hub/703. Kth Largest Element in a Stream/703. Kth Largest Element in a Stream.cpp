class KthLargest {
    private final int k;
    private final int[] arr;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        this.arr = new int[k];
        Arrays.fill(arr, Integer.MIN_VALUE);
        for (int num : nums)
            add(num);
    }
    
    public int add(int val) {
        if (val <= arr[0])
            return arr[0];
        int pos = findPos(val);
        for (int i = 0; i < pos; i++)
            arr[i] = arr[i + 1];
        arr[pos] = val;
        return arr[0];
    }
    
    private int findPos(int val) {
        int l = 0;
        int r = k -1;
        while (l <= r)
        {
            int m = (r - l) / 2 + l;
            if (arr[m] == val)
                return m;
            else if (arr[m] > val)
                r = m - 1;
            else
                l = m + 1;
        }
        return r;
    }
}