const express = require("express");
const cors = require("cors");
const { exec } = require("child_process");

const app = express();
app.use(cors());
app.use(express.json());

app.post("/run", (req, res) => {
  const { tasks, algorithm } = req.body;

  // Convert tasks into input string
  let input = `${algorithm}\n${tasks.length}\n`;
  tasks.forEach(t => {
    input += `${t.name} ${t.burst}\n`;
  });

  exec("focusforge.exe", (error, stdout, stderr) => {
    if (error) {
      return res.status(500).send("Error running scheduler");
    }
    res.send(stdout);
  });
});

app.listen(5000, () => {
  console.log("Server running on port 5000");
});