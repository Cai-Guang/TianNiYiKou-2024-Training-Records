--- Original
+++ New
@@ @@
     int ans = 1e18;
     int cnt = 0;
     vector<int> row(n + 1);
+    int flg = 0;
     for (int i = 1; i <= n * m; i ++) {
         int y = a[i] % m;
         int x = a[i] / m + 1;
         if (y == 0) x --;
         row[x] ++;
+        if (flg && i >= m) {
+            ans = i;
+            break;
+        }
+        if (row[x] + k >= m) {
+            flg = 1;
+        }
         if (i >= m && row[x] + k >= m) {
             ans = i;
             break;