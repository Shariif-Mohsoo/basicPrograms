function pick(arr) {
  const idx = Math.floor(Math.random() * arr.length);
  return arr[idx];
}
function getCard() {
  const values = ["A", 2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "K", "Q"];
  const suits = ["Heart", "Club", "Spade", "Diamond"];
  return { suit: pick(suits), value: pick(values) };
}
console.log(getCard());
