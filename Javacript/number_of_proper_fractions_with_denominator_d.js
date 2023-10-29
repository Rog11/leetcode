const gcd = (n, d) => {
  return d === 0 ? n: gcd(d, n% d);
}

const properFractions = (d) => {
  if(d === 0 || d === 1) {
    return 0; 
  }
  if(d === 2) {
    return 1; 
  }
  let count = 0; 
  let n = 0; 
  while(n < d) {
    if(gcd(n, d) === 1) {
      count++;
    }
    n++
  }
  return count; 
}