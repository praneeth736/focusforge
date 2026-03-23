import { useState } from "react";

function Dashboard() {
  const [output, setOutput] = useState("");

  const runScheduler = async () => {
  try {
    const res = await fetch("/output.txt");
    const text = await res.text();

    if (!text.trim()) {
      setOutput("⚠️ No execution yet. Please run the scheduler.");
    } else {
      setOutput(text);
    }
  } catch (err) {
    setOutput("Error loading output.txt");
  }
};

  return (
    <div style={{ padding: "20px", fontFamily: "Arial" }}>
      
      {/* 🔥 TITLE UPDATED */}
      <h1>🚀 FocusForge</h1>
      <h3>Intelligent OS Scheduler Visualization</h3>

      <button onClick={runScheduler}>Show Output</button>

      <h3>Execution Output</h3>
      <pre>{output}</pre>
    </div>
  );
}

export default Dashboard;