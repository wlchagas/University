import java.util.HashMap;

public class JavaBancoPessoas 
{
	HashMap<String, Command> CommandList;
	HashMap<Long, String> PersonList;
	
	public JavaBancoPessoas()
	{
		CommandList = new HashMap();
		Command get = new CommandGet();
		Command all = new CommandAll();
		Command delete = new CommandDelete();
		Command novo = new CommandNew();
		CommandList.put("get", get);
		CommandList.put("all", all);
		CommandList.put("delete", delete);
		CommandList.put("novo", novo);
	}
	
	public void getCommand(String CommandName, Long id, String nome)
	{
		Command c = CommandList.get(CommandName);
		c.execute(PersonList, id, nome);
	}
	
}