import React, { useState } from "react";
import "./App.css"; 

function App() {

  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const [submitted, setSubmitted] = useState(false);

  const handleSubmit = (e) => {
    e.preventDefault(); 
    setSubmitted(true); 
  };

  return (
    <div className="App">
      <form className="cover" onSubmit={handleSubmit}>
        <h1>Login <span>Here!!</span></h1>

        <input
          type="text"
          placeholder="Enter Name"
          name="username"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
        />

        <input
          type="password"
          placeholder="Enter Password"
          name="password"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
        />

        <button type="submit">SUBMIT</button>
      </form>

      {submitted && (
        <div className="result">
          <h3>Entered Details:</h3>
          <p><strong>Username:</strong> {username}</p>
          <p><strong>Password:</strong> {password}</p>
        </div>
      )}
    </div>
  );
}

export default App;