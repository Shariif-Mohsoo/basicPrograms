const btn = document.body.querySelector(".button");
console.log(btn);
const moveX = (ele, amount, delay) => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      const right = ele.getBoundingClientRect().right;
      const left = ele.getBoundingClientRect().left;
      const layout = document.body.clientWidth;
      if (right + amount >= layout) {
        reject({ right, amount, layout });
      } else {
        ele.style.transform = `translateX(${amount + left}px)`;
        resolve();
      }
    }, delay);
  });
};
moveX(btn, 100, 1000)
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .then(() => moveX(btn, 100, 1000))
  .catch((err) => {
    const { right, amount, layout } = err;
    alert(
      `Can't move further body is ${layout}px wide and you are to moving ${Math.floor(
        right + amount
      )}px at this time which is not possible.`
    );
  });
