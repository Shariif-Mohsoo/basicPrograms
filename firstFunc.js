function isValidPassword(user, pass) {
  let password = pass.toLowerCase();
  let userName = user.toLowerCase();
  if (
    password.length >= 8 &&
    password.indexOf(" ") === -1 &&
    !password.includes(userName)
  )
    return "Accepted";
  else return "Access denied";
}

function call(func) {
  let output;
  for (let i = 1; i < 3; i++) {
    output = func("Mohsin", "Rajpoot@123232");
    console.log(output);
  }
}
call(isValidPassword); //TODO: passing the function callback.
