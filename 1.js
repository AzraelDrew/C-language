let m = 7;
let n = 4;
let array = new Array();

for (let i = 0; i < m; i++) {
  array[i] = new Array();
  for (let j = 0; j < n; j++) {
    array[i][j] = 0;
  }
}
for (let i = 0; i < m; i++) {
  for (let j = 0; j < n; j++) {
    console.log(array[i][j]);
  }
  // console.log("\n");
}