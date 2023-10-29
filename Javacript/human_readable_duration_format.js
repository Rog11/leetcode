const ending = x => {
  return x !== 1 ? 's' : '';
};

const formatDuration = seconds => {
  if (seconds === 0) return 'now';
  let res = [];
  
  const times = {
    years: seconds === 1 ? 0 : parseInt(seconds / 31536000),
    days: parseInt((seconds / 86400) % 365),
    hours: parseInt((seconds / 3600) % 24),
    minutes: parseInt((seconds / 60) % 60),
    seconds: seconds % 60
  };
  
  for (const time in times) {
    if (times[time] === 0) delete times[time];
    else res.push(`${times[time]} ${time.slice(0, -1)}${ending(times[time])}`);
  }
  
  return res.join(', ').replace(/,([^,]*)$/, ` and$1`);
}

console.log(formatDuration(1));