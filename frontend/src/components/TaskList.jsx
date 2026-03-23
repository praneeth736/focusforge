const TaskList = ({ tasks, removeTask }) => {
  if (tasks.length === 0) {
    return <p>No tasks added yet.</p>;
  }

  return (
    <div>
      <h3>Current Tasks</h3>

      <table border="1" cellPadding="8">
        <thead>
          <tr>
            <th>Name</th>
            <th>Burst</th>
            <th>Priority</th>
            <th>Arrival</th>
            <th>Action</th>
          </tr>
        </thead>

        <tbody>
          {tasks.map((task, index) => (
            <tr key={index}>
              <td>{task.name}</td>
              <td>{task.burst}</td>
              <td>{task.priority}</td>
              <td>{task.arrival}</td>
              <td>
                <button onClick={() => removeTask(task.name)}>
                  Remove
                </button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default TaskList;
