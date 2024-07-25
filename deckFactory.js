const deckFactory = () => {
  return {
    deck: [],
    drawlDeck: [],
    suits: ["Heart", "Diamond", "Club", "Spade"],
    values: "2,3,4,5,6,7,8,9,10,A,K,Q,J",
    initializeDeck() {
      const { values, suits, deck } = this;
      for (let value of values.split(",")) {
        for (let suit of suits) {
          deck.push({ value, suit });
        }
      }
    },
    getLength(arr) {
      if (Array.isArray(arr)) {
        return arr.length;
      }
      return "Invalid; Input must be an array";
    },
    withDrawlCard() {
      const { deck, drawlDeck } = this;
      const card = deck.pop();
      drawlDeck.push(card);
      return card;
    },
    withDrawlMultipleCards(times) {
      const cards = [];
      while (times) {
        cards.push(this.withDrawlCard());
        times--;
      }
      return cards;
    },
    shuffleDeck() {
      const { deck } = this;
      for (let i = deck.length - 1; i > 0; i--) {
        let idx = Math.floor(Math.random() * i + 1);
        [deck[i], deck[idx]] = [deck[idx], deck[i]];
      }
    },
    display(val) {
      console.log(val);
    },
  };
};

let newDeck = deckFactory();
newDeck.initializeDeck();
newDeck.display(newDeck.deck);
// console.log(newDeck.getLength(1)); //ARGUMENT IS NOT AN ARRAY
console.log("Length: ", newDeck.getLength(newDeck.deck));
newDeck.shuffleDeck();
newDeck.display(newDeck.deck);
console.log("With Drawl Card: ", newDeck.withDrawlCard());
console.log("Length: ", newDeck.getLength(newDeck.deck));
console.log("With Drawl Cards:", newDeck.withDrawlMultipleCards(3));
console.log("Length: ", newDeck.getLength(newDeck.deck));
newDeck.display(newDeck.deck);
