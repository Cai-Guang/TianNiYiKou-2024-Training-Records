--- Original
+++ New
@@ @@
     vector<int> row(n + 1);
     for (int i = 1; i <= n * m; i ++) {
         int y = a[i] % m;
-        int x = a[i] / m;
+        int x = a[i] / m + 1;
+        if (y == 0) x --;
         row[x] ++;
         if (i >= m && row[x] + k >= m) {
-            ans  = i;
+            ans = i;
             break;
         }
     }