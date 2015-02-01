<Query Kind="Statements">
  <Connection>
    <ID>3783d8f6-d5cf-4354-a7a8-8cc53301e606</ID>
    <Persist>true</Persist>
    <Driver Assembly="CrmLINQPadPlugin" PublicKeyToken="ec279e9c96512601">CrmLINQPadPlugin.CrmDataContextDriver</Driver>
    <CustomAssemblyPathEncoded>&lt;CommonApplicationData&gt;\LINQPad\Drivers\DataContext\4.0\CrmLINQPadPlugin (ec279e9c96512601)\datacontext_1415456181.dll</CustomAssemblyPathEncoded>
    <CustomAssemblyPath>C:\ProgramData\LINQPad\Drivers\DataContext\4.0\CrmLINQPadPlugin (ec279e9c96512601)\datacontext_1415456181.dll</CustomAssemblyPath>
    <CustomTypeName>LINQPadCrmPlugin1415456181.CrmDataContextDerived</CustomTypeName>
    <IsProduction>true</IsProduction>
    <DriverData OrganizationUrl="https://crm.dotnetfabrik.de/zeteko" AuthenticationProviderType="1" HasCredentials="True" Password="access" UserName="zeteko\sas" />
  </Connection>
</Query>

foreach (XElement state in XElement.Load(@"C:\Work\TFS\Dev\Turing\_Resources\3bit Addition.xml").Elements("STATE"))
{
	var stateName = state.Attribute("name").Value.Replace("q_", string.Empty);
	var stateFinal = state.Attribute("finalstate").Value == "true";
	foreach (XElement transition in state.Elements("TRANSITION"))
	{
		var transitionTarget = transition.Attribute("target").Value.Replace("q_", string.Empty);
		foreach (XElement label in transition.Elements("LABEL"))
		{
			var labelRead = label.Attribute("read").Value;
			var labelDirection = label.Attribute("direction").Value;
			var labelWrite = label.Attribute("write").Value;
			char directionChar;
			switch (labelDirection)
			{
				case "RIGHT":
					directionChar = 'R';
					break;
				case "LEFT":
					directionChar = 'L';
					break;
				case "NONE":
					directionChar = 'N';
					break;
				default:
					throw new ArgumentOutOfRangeException("Unbekannte Bewegungsrichtung!");
			}
			Console.WriteLine("{0},{1}->{2},{3},{4}", stateName, labelRead, transitionTarget, labelWrite, stateFinal ? 'S' : directionChar);
		}
	}
}