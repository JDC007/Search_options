import numpy as np
import pandas as pd

data_path = 'data.csv'
dataframe = pd.read_csv(data_path)
#print (dataframe.head())
#print (len(dataframe))

def print_options():
	print("#############################################")
	print("1. Search all parameters by a city name")
	print("2. Search by a city name and a specific parameter")
	print("3. Search all data of a specific parameter")
	print("4. Search all parameters' data by a year")
	print("5. Search all parameters' data by a month")
	print("6. Search all parameters' data by a specific date")
	print("7. Search all parameters' data by an hour")
	print("8. Exit the program")
	print("#############################################\n")
	option = input("Please select a search option from above: ")

	return option

while True:
	option = print_options()

	if option == '1':
		city_name = input("Please enter a city name (ex: Geneva): ")

		df_temp = dataframe
		city_arr = df_temp[['city']].values.flatten()
		city_list = np.unique(city_arr)
		index_arr = np.where(city_list == city_name)[0]
		
		if len(index_arr) != 0:
			print("\nAll the environmental data of", city_name + ":")
			df = dataframe[dataframe.city==city_name]
			print(df)
			print()
		else:
			print("\nInvalid City! Please input a valid city from this list:")
			print(city_list)
			print()

	elif option == '2':
		city_name = input("Please enter a city name (ex: Geneva): ")
		para = input("Now enter a specific parameter (ex: dust): ")
		print("All", para, "data of", city_name + ":")
		df1 = dataframe[dataframe.city==city_name]
		df2 = df1[[para]]
		print(df2)
		print()

	elif option == '3':
		para = input("Please enter a specific parameter: ")
		print("All", para, "data:")
		df = dataframe[[para]]
		print(df)
		print()

	elif option == '4':
		user_year = input("Please enter a year (ex:2015): ")
		print("\nAll the environmental data of year ", user_year + ": ")
		df = dataframe[0:1000]
		for i in range(len(df)):
			tstamp = df[['timestamp']].loc[i].values[0]
			#print(tstamp)
			year = tstamp.split('-')[0]
			#print(year)
		
			if year != user_year:
				#print(year, i)
				df = df.drop([i])
				#print("index", i, "of panda dataframe has been dropped!")
		print(df)
		print()

	elif option == '5':
		month_name = {'JAN':'01', 'FEB':'02', 'MAR':'03', 'APR':'04', 'MAY':'05', 'JUN':'06',
				  'JUL':'07', 'AUG':'08', 'SEP':'09', 'OCT':'10', 'NOV':'11', 'DEC':'12'}
		user_month = input("Please enter the first three letters of a month (ex: FEB): ")
		print("\nAll the environmental data of month: ", user_month)
		user_month_index = month_name[user_month]
		print(user_month_index)

		df = dataframe[0:1000]
		for i in range(len(df)):
			tstamp = df[['timestamp']].loc[i].values[0]
			#print(tstamp)
			month = tstamp.split('-')[1]
			#print(month)
		
			if month != user_month_index:
				#print(month, i)
				df = df.drop([i])
				#print("index", i, "of panda dataframe has been dropped!")
		print(df)
		print()

	elif option == '6': 
		user_date = input("Please enter a date (ex: 2015-01-07): ")
		print("\nAll the environmental data of", user_date + ": ")
		#df = dataframe[0:10000] #to load first 10000 rows
		df = dataframe[0:1000] 
		for i in range(len(df)):
			tstamp = df[['timestamp']].loc[i].values[0]
			#print(tstamp)
			date = tstamp.split('T')[0]
			#print(date)
			
			if date != user_date:
				#print(date, i)
				df = df.drop([i])
				#print("index", i, "of panda dataframe has been dropped!")
		print(df)
		print()

	elif option == '7':
		user_hour = input("Please enter an hour (ex: 20): ")
		print("\nAll the environmental data of hour", user_hour+ ":")
		df = dataframe[0:1000]
		for i in range(len(df)):
			tstamp = df[['timestamp']].loc[i].values[0]
			#print(tstamp)
			hour_init = tstamp.split('T')[1]
			hour = hour_init.split(':')[0]
			#print(date)
			
			if hour != user_hour:
				#print(date, i)
				df = df.drop([i])
				#print("index", i, "of panda dataframe has been dropped!")
		if len(df) != 0:
			print(df)
			print()
		else:
			print("Oooops! No data available for hour:", user_hour + "!\n")

	elif option == '8':
		print("Thank you! See you later!")
		break

	else:
		print("Invalid input! Please enter a valid input!\n")
