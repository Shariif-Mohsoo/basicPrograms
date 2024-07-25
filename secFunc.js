function isPangram(statement) {
  let sentence = statement.toLowerCase();
  let alphabets = "abcdefghijklmnopqrstuvwxyz";
  for (let alpha of alphabets) {
    if (!sentence.includes(alpha)) return "Invalid";
  }
  return "Valid";
}
const output = isPangram("The quick brown fox jumps over the lazy dog");
console.log(output);
