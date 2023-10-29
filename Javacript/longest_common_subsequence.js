function lcs(x,y) {
  var xSub = x.substr(0, x.length -1); 
  var ySub = y.substr(0, y.lenght -1); 
  
  if (x.length === 0 || y.length === 0) {
    return ''; 
  } else if (x.charAt(x.length -1) === y.charAt(y.length -1)) {
    return lcs(xSub, ySub) + x.charAt(x.length -1); 
  } else {
    var a = lcs(x, ySub); 
    var b = lcs(xSub, y); 
    return (a.length > b.length) ? a: b; 
  }
}