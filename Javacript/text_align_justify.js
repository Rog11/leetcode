var justify = function(str, len) {
    var res = [];
    var fn = "";
    var i = 0;
    var l = 0;
    str = str.split(" ");
    while (i < str.length){
        if ((fn.length + str[i].length) <= len) {
            fn += str[i] + " ";
        }
        else {
            res.push(fn.trim());
            fn = "";
            i--;
        }
        i++;
    }
    res.push(fn.trim());
    for (var i = 0; i < res.length-1; i++) {
        l = len - res[i].length;
        res[i] = res[i].split(" ");
        if (res[i].length != 1) {
            while (l > 0) {
                for (var j = 0; j < res[i].length-1; j++) {
                    if (l > 0){
                        res[i][j] += " ";
                    }
                    l -= 1;
                }
            }
        }
        res[i] = res[i].join(" ");
    }
    return res.join("\n");
  };