@fix_if@
expression E;
@@
- if (E) {
- return true;
- } else {
- return false;
- }
+ return E;