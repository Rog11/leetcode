var nums = { zero: 0, one: 1, two: 2, three: 3, four: 4, five: 5, six: 6, seven: 7, eight: 8, nine: 9, ten: 10 };

var ops = {
  plus: function(a, b) { return a + b; },
  minus: function(a, b) { return a - b; },
  times: function(a, b) { return a * b; },
  dividedBy: function(a, b) { return a / b; }
};

function createNumProperties(numMap) {
  var numProps = {};
  
  for (var n in numMap) {
    const num = numMap[n];
    numProps[n] = {
      get: function() {
        var result;
        if (Number.prototype.lastOperation) {
          result = Number.prototype.lastOperation(this, num);
          Number.prototype.lastOperation = undefined;
        } else {
          if (Number.prototype.lastPropGet && Number.prototype.lastPropGet === 'number') {
            return undefined;
          }
          result = Number(num);
        }
        Number.prototype.lastPropGet = 'number';
        return Number(result);
      }
    }
  }
  
  return numProps;
}

Object.defineProperties(Number.prototype, createNumProperties(nums));

function createOpProperties(opsMap) {
  var opsProps = {};
  
  for (var op in opsMap) {
    const operation = opsMap[op];
    opsProps[op] = {
      get: function() {
        if (Number.prototype.lastOperation === operation) {
          Number.prototype.lastOperation = undefined;
          return undefined;
        }
        Number.prototype.lastOperation = operation;
        Number.prototype.lastPropGet = 'operation';
        return Number(this);
      }
    }
  }
  
  return opsProps;
}

Object.defineProperties(Number.prototype, createOpProperties(ops));

var Magic = {
  zero: Number(0),
  one: Number(1),
  two: Number(2),
  three: Number(3),
  four: Number(4),
  five: Number(5),
  six: Number(6),
  seven: Number(7),
  eight: Number(8),
  nine: Number(9),
  ten: Number(10)
};

console.log('end result', Magic.one.plus.one.plus.one)
console.log('end result', Magic.one.plus.one)
console.log('end result', Magic.ten.times.two)