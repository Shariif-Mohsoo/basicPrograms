const userName = document.querySelector("#user");
const password = document.querySelector("#password");
const form = document.querySelector("form");
const button = document.querySelector("input[type='submit']");
const users = [];
password.addEventListener("input", checkPass);
let flag;
function checkPass() {
  let val = password.value;
  if (val.includes(userName.value) || val.length < 8) {
    password.style.borderBottom = "3px solid red";
    flag = false;
  } else {
    password.style.borderBottom = "3px solid green";
    flag = true;
    button.style.transform = `translate(${0}px,${0}px)`;
  }
}
button.addEventListener("mouseover", moveAroundScreen);

function moveAroundScreen() {
  if (flag === false) {
    const x = Math.floor(Math.random() * window.innerWidth) - 250;
    const y = Math.floor(Math.random() * window.innerHeight) - 250;
    if (x < window.innerWidth && y < window.innerHeight)
      button.style.transform = `translate(${x}px,${y}px)`;
    else button.style.transform = `translate(0px,0px)`;
  }
}

form.addEventListener("submit", funcSubmit);
function funcSubmit(e) {
  const data = {};
  e.preventDefault();
  data.Name = userName.value;
  data.password = password.value;
  users.push(data);
  userName.value = "";
  password.value = "";
}
console.log(users);
