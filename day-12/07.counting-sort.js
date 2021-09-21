function countSort(arr) {
  let max = arr[0];
  for (let i = 1; i < arr.length; i++) {
    max = Math.max(max, arr[i]);
  }

  const temp = new Array(max + 1).fill(0);
  for (let i = 0; i < arr.length; i++) {
    temp[arr[i]]++;
  }

  for (let i = 1; i < temp.length; i++) {
    temp[i] += temp[i - 1];
  }
  console.log(temp);
  const output = new Array(arr.length);
  for (let i = 0; i < arr.length; i++) {
    output[--temp[arr[i]]] = arr[i];
  }

  console.log(output);
}

var arr = [9, 8, 7, 5, 6, 4, 5, 2, 3, 1, 1];
countSort(arr);
