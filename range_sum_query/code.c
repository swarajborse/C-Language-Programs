typedef struct {
    int* seg;
    int n;
} NumArray;

int buildTree(int* seg, int* nums, int idx, int l, int r) {
    if (l == r) {
        seg[idx] = nums[l];
        return seg[idx];
    }
    int mid = (l + r) / 2;
    seg[idx] =
        buildTree(seg, nums, 2 * idx + 1, l, mid) +
        buildTree(seg, nums, 2 * idx + 2, mid + 1, r);
    return seg[idx];
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->n = numsSize;

    int size = 4 * numsSize;  
    obj->seg = (int*)malloc(sizeof(int) * size);
    buildTree(obj->seg, nums, 0, 0, numsSize - 1);

    return obj;
}

void updateTree(int* seg, int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        updateTree(seg, 2 * idx + 1, l, mid, pos, val);
    else
        updateTree(seg, 2 * idx + 2, mid + 1, r, pos, val);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    updateTree(obj->seg, 0, 0, obj->n - 1, index, val);
}

int query(int* seg, int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return seg[idx];
    if (qr < l || r < ql)
        return 0;

    int mid = (l + r) / 2;
    return query(seg, 2 * idx + 1, l, mid, ql, qr) +
           query(seg, 2 * idx + 2, mid + 1, r, ql, qr);
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return query(obj->seg, 0, 0, obj->n - 1, left, right);
}

void numArrayFree(NumArray* obj) {
    free(obj->seg);
    free(obj);
}
