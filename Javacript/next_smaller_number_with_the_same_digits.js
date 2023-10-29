const nextSmaller = n => {
  let min = minify(n); 
  while(--n >= min) if(minify(n) === min) return n; 
  return -1
}

const minify = n => [...`${n}`].sort().join``.replace(/^(0+)[0-9]/, '$2$1'); 
